#include <bits/stdc++.h>
using namespace std;
vector<int> edges[100005];
int A[100005];
void dfs(int n, int v) { // v>=n
    if (!A[n]) {
        A[n] = v;
        for (auto x:edges[n]) {
            dfs(x, v);
        }
    }
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i=1; i<=m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        edges[v].push_back(u);
    }
    for (int i=n; i>=1; --i) {
        dfs(i, i);
    }
    for (int i=1; i<=n; ++i) {
        printf("%d ", A[i]);
    }
    return 0;
}
