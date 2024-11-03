#include <bits/stdc++.h>
using namespace std;
int reachable[1005];
vector<int> edges[1005];
vector<int> spec_node;
int k;
int ans=0;
bool vis[1005];
void dfs(int n) {
    vis[n] = true;
    reachable[n]++;
    for (int dn: edges[n]) {
        if (!vis[dn]) {
            dfs(dn);
        }
    }
}
void ldfs(int n) {
    vis[n] = true;
    reachable[n]++;
    if (reachable[n]==k) ++ans;
    for (int dn: edges[n]) {
        if (!vis[dn]) {
            ldfs(dn);
        }
    }
}
int main() {
    int m, n;// m: edge n: node k: spec node
    scanf("%d%d%d", &k, &n, &m);
    for (int i=1; i<=k; ++i) {
        int x;
        scanf("%d", &x);
        spec_node.push_back(x);
    }
    for (int i=1; i<=m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        edges[x].push_back(y);
    }
    for (int i=0; i<=spec_node.size()-1-1; ++i) {
        dfs(spec_node[i]);
        memset(vis, 0, sizeof(vis));
    }
    ldfs(spec_node[spec_node.size()-1]);
    printf("%d", ans);
    return 0;
}
