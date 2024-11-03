#include <bits/stdc++.h>
using namespace std;
int n;
struct Node {
    int n;
    int left;
    int right;
    int root;
} t[105];
int p=1;
int bfs(int rt) {
    int ans=0;
    bool vis[105];
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int>> Q; // 根节点: node, dis
    Q.push({rt, 0});
    while (!Q.empty()) {
        int node = Q.front().first;
        int dis = Q.front().second;
        Q.pop();
        if (!vis[node]) {
            vis[node]=true;
            if (t[node].left) {
                Q.push({t[node].left, dis+1});
            }
            if (t[node].right) {
                Q.push({t[node].right, dis+1});
            }
            if (t[node].root) {
                Q.push({t[node].root, dis+1});
            }
            ans+=dis*t[node].n;
        }
    }
    return ans;
}
int main() {
    // 节点总距离=周围总距离+自身距离*人数
    scanf("%d", &n);
    for (int i=1; i<=n; ++i) {
        scanf("%d%d%d", &t[p].n, &t[p].left, &t[p].right);
        if (t[p].left!=0)
            t[t[p].left].root=p;
        if (t[p].right!=0)
            t[t[p].right].root=p;
        p++;
    }
    int mdis = INT_MAX;
    for (int i=1; i<=n; ++i) {
        int cur = bfs(i);
        if (cur<mdis)
            mdis = cur;
    }
    printf("%d", mdis);
    return 0;
}
