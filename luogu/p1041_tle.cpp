#include <bits/stdc++.h>
using namespace std;
int n, p;

// 贪心(树的深度?) 决策? 显然错误
// 先dfs一下树, 标记每个节点构成树的大小
// 将感染者的分数归0
// 开始传播，
vector<int> inf[305]; // [回合数]->节点集合
vector<int> adj[305];
bool vis[305]; // for bfs
int root[305]; // created on bfs
int inf_turn[305];
int min_inf = INT_MAX;
bool cut[305];
// 建无向图
// 先跑一遍bfs, 深度d赋节点表示第d回合被感染 (1是第0回合)
// 枚举要剪的节点(感染者子节点)(递归父节点确认未剪掉)
// 节点标记为剪掉
// 剪了后继续dfs
// 直到没有要剪的节点递归结束, bfs一遍感染者, 记录最小值
void link(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
}
bool is_cut(int x) {
    if (x==0) return false;
    else if (cut[x]) return true;
    else return is_cut(root[x]);
}
void dfs(int depth) {
    printf("dfs, depth:%d\n",depth);
    bool has_iter = false;
    for (int x: inf[depth]) {
        if (!is_cut(x)) {
            has_iter = true;
            cut[x] = true;
            dfs(depth+1);
            cut[x] = false;
        }
    }
    if (!has_iter) {
        // 递归结束, 剪无可剪
        memset(vis, 0, sizeof(vis));
        queue<int> Q;
        Q.push(1);
        int cnt=0;
        while (!Q.empty()) {
            int x = Q.front(); Q.pop();
            vis[x] = true;
            ++cnt;
            for (int d: adj[x]) {
                if (!vis[d]&&!cut[d]) Q.push(d);
            }
        }
        min_inf = min(min_inf, cnt);
    }
}
int main() {
    cin>>n>>p;
    for (int i=1; i<=p; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        link(a, b);
    }
    // bfs
    queue<pair<int, int>> Q;// 节点, 深度
    Q.push({1, 0});
    while (!Q.empty()) {
        int x = Q.front().first, dep = Q.front().second;
        Q.pop();
        vis[x] = true;
        inf[dep].push_back(x);
        for (int d: adj[x]) {
            if (!vis[d]) {
                Q.push({d, dep+1});
                root[d] = x;
            }
        }
    }// debug
    /*printf("Endbfs\n");
    for (int i=1; i<=n; ++i) {
        printf("Root %d is %d\n", i, root[i]);
        printf("Turn %d: ", i);
        for (int j: inf[i]) {
            printf("%d ", j);
        }
        putchar('\n');
    }//de */
    // endbfs
    dfs(1);
    printf("%d", min_inf);
}
