#include <bits/stdc++.h>
using namespace std;
vector<int> edges[5005]; // 权数，边, 入
vector<int> oute[5005]; // 出
int deg[5005]; // 入度
vector<int> zero;
vector<int> ozero;
int chains[5005]; // 从0到达节点的食物链条数
void dfs(int zn) {
    // 计算从zn开始的最大食物链条数
    chains[zn] = 1;
    queue<int> Q; // 待处理队列
    Q.push(zn);
    while (!Q.empty()) {
        int x= Q.front();Q.pop();
        for (auto i:edges[x]) {
            chains[x]+=chains[i];
            chains[x]%=80112002;
        }
        for (auto e:oute[x]) {
            --deg[e];
            if (deg[e]==0)
                Q.push(e);
        }
    }
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i=1; i<=m; ++i) {
        // b->a
        int a, b;
        scanf("%d%d", &a, &b);
        edges[a].push_back(b);
        oute[b].push_back(a);
    }
    for (int i=1; i<=n; ++i) {
        if ((deg[i] = edges[i].size())==0) zero.push_back(i);
        if (oute[i].size()==0) ozero.push_back(i);
    }
    int ans=0;
    for (auto n:zero) {
        dfs(n);
    }
    for (auto n:ozero) {
        ans+=chains[n];
        ans%=80112002;
    }
    printf("%d", ans);
    return 0;
}
