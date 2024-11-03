#include <bits/stdc++.h>
using namespace std;
int f[10005][105];
int dishes[105];
int n, m;
int methods(int x, int s) { // s: dishes[s]开头
    if (x<0) return 0;
    if (f[x][s]!=-1) return f[x][s];
    int result=0;
    for (int i=s; i<=n; ++i) {
        result+=methods(x-dishes[i], i+1);
    }
    return f[x][s] = result;
}
int main() {
    scanf("%d%d", &n, &m);
    memset(f, -1, sizeof(f));
    for (int i=0; i<=m; ++i) f[i][n+1] = 0;
    for (int j=0; j<=n+1; ++j) f[0][j] = 1;
    for (int i=1; i<=n; ++i)
        scanf("%d", &dishes[i]);
    printf("%d", methods(m, 1));
}

