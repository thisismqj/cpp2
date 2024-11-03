#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 105

int n;
double mat[maxn][maxn];
double imat[maxn][maxn];
void apply(double (*mat)[maxn], int n, int l1, int l2, double sc) {
    for (int i=1; i<=n; ++i) {
        mat[l2][i] += mat[l1][i]*sc;
    }
}
void apply_v(double (*mat)[maxn], int n, int c1, int c2, double sc) {
    for (int i=1; i<=n; ++i) {
        mat[i][c2] += mat[i][c1]*sc;
    }
}
double det(double (*pmat)[maxn], int n) {
    double *ptr_mat = (double *)malloc(maxn*maxn*sizeof(double));
    memcpy(ptr_mat, pmat, maxn*maxn*sizeof(double));
    double (*mat)[maxn] = (double (*)[maxn])ptr_mat;
    double ans = 1.;
    for (int i=1; i<=n-1; ++i) {
        if (mat[i][i]==0) {
            bool all_zero = true;
            for (int j=1; j<=n; ++j) {
                if (mat[i][j]!=0) {
                    all_zero = false;
                    apply_v(mat, n, j, i, 1);
                    break;
                }
            }
            if (all_zero) return 0.;
        }
    }
    for (int i=1; i<=n-1; ++i) {
        for (int j=i+1; j<=n; ++j) {
            apply(mat, n, i, j, -mat[j][i]/mat[i][i]);
        }
    }
    for (int i=1; i<=n; ++i) {
        ans*=mat[i][i];
    }
    free(ptr_mat);
    return ans;
}
double am(double (*pmat)[maxn], int n, int l, int c) { // 代数余子式
    double *ptr_mat = (double *)malloc(maxn*maxn*sizeof(double));
    memcpy(ptr_mat, pmat, maxn*maxn*sizeof(double));
    double (*mat)[maxn] = (double (*)[maxn])ptr_mat;
    double ans = 1;
    for (int i=1, j=1; i<=n-1&&j<=n-1; ++i, ++j) {
        if (i==l) ++i;
        if (i>n-1) break;
        if (j==c) ++j;
        if (j>n-1) break;
        if (mat[i][j]==0) {
            bool all_zero = true;
            for (int k=1; k<=n; ++k) {
                if (k==c) ++k;
                if (k>n) break;
                if (mat[i][k]!=0) {
                    all_zero = false;
                    apply_v(mat, n, k, j, 1);
                    break;
                }
            }
            if (all_zero) return 0.;
        }
    }
    for (int i=1, j=1; i<=n-1&&j<=n-1; ++i, ++j) {
        if (i==l) ++i;
        if (i>n-1) break;
        if (j==c) ++j;
        if (j>n-1) break;
        for (int k=i+1; k<=n; ++k) {
            apply(mat, n, i, k, -mat[k][j]/mat[i][j]);
        }
    }
    for (int i=1, j=1; i<=n&&j<=n; ++i, ++j) {
        if (i==l) ++i;
        if (i>n) break;
        if (j==c) ++j;
        if (j>n) break;
        ans*=mat[i][j];
    }
    free(ptr_mat);
    return ans*(((l+c)%2==0)?1:-1);
}
int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; ++i)
    for (int j=1; j<=n; ++j) {
        scanf("%lf", &mat[i][j]);
    }
    double d_A = det(mat, n);
    // 算行列式加上
    // printf("%lf\n", d_A);
    if (d_A==0) {
        printf("Not exist!\n");
    } else {
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=n; ++j) {
                imat[i][j] = am(mat, n, j, i) / d_A;
                printf("%.3lf\t", imat[i][j]);
            }
            putchar('\n');
        }
    }
}
