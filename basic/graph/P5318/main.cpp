#include <bits/stdc++.h>
using namespace std;
vector<int> g[100005];
bool vis[100005];
void dfs(int x) {
    printf("%d ", x);
    vis[x] = true;
    for (auto i:g[x]) {
        if (!vis[i])
            dfs(i);
    }
}
void bfs() {
    queue<int> Q;
    Q.push(1);
    while (!Q.empty()) {
        while (!Q.empty() && vis[Q.front()]) Q.pop();
        if (Q.empty()) break;
        int x=Q.front();
        Q.pop();
        printf("%d ", x);
        vis[x] = true;
        for (auto i:g[x]) {
            if (!vis[i])
                Q.push(i);
        }
    }
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i=1; i<=m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
    }
    for (int i=1; i<=n; ++i) {
        sort(g[i].begin(), g[i].end());
    }
    dfs(1);
    putchar('\n');
    memset(vis, 0, sizeof(vis));
    bfs();
    return 0;
}
