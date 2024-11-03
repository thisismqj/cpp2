#include <stdio.h>
int n;
const int maxn=105;
double mat[maxn][maxn];
inline void apply(int l1, int l2, double sc) {
    for (int i=1; i<=n; ++i) {
        mat[l2][i] += mat[l1][i]*sc;
    }
}
double ans = 1.;
int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; ++i)
    for (int j=1; j<=n; ++j) {
        scanf("%lf", &mat[i][j]);
    }
    for (int i=1; i<=n-1; ++i) {
        for (int j=i+1; j<=n; ++j) {
            apply(i, j, -mat[j][i]/mat[i][i]);
        }
    }
    for (int i=1; i<=n; ++i) {
        ans*=mat[i][i];
    }
    printf("%lf", ans);
}
