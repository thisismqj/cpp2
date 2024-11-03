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
int cut_cnt = 0;
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
inline bool is_cut(int x) {
    return cut[x];
}
int do_cut(int x) { // 返回切树大小
    int cnt=0;
    for (int e: adj[x]) {
        if (e!=root[x]) {
            cnt+=do_cut(e);
        }
    }
    cut[x] = true;
    return cnt+1;
}
void undo_cut(int x) {
    for (int e: adj[x]) {
        if (e!=root[x]) {
            undo_cut(e);
        }
    }
    cut[x] = false;
}
void dfs(int depth) {
    bool cut_bak[305];
    memcpy(cut_bak, cut, 305);
    // printf("dfs, depth:%d\n",depth);
    bool has_iter = false;
    for (int x: inf[depth]) {
        if (!is_cut(x)) {
            has_iter = true;
            int ccnt = do_cut(x);
            cut_cnt += ccnt;
            dfs(depth+1);
            cut_cnt -= ccnt;
            memcpy(cut, cut_bak, 305);
        }
    }
    if (!has_iter) {
        // 递归结束, 剪无可剪
        min_inf = min(min_inf, n-cut_cnt);
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
