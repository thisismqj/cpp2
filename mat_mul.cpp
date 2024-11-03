#include <stdio.h>
#define maxn 105
double mat1[maxn][maxn];
double mat2[maxn][maxn];
double ans_mat[maxn][maxn];
int i1, j1, i2, j2;
void read(double mat[][maxn], int *i1, int *j1) {
    scanf("%d%d", i1, j1);
    for (int i=1; i<=*i1; ++i)
    for (int j=1; j<=*j1; ++j) {
        scanf("%lf", &mat[i][j]);
    }
}
void print(double mat[][maxn], int i1, int j1) {
    for (int i=1; i<=i1; ++i) {
        for (int j=1; j<=j1; ++j) {
            printf("%.3lf\t", mat[i][j]);
        }
        putchar('\n');
    }
}
int main() {
    read(mat1, &i1, &j1);
    read(mat2, &i2, &j2);
    if (j1!=i2) {
        printf("Can't do\n");
    } else {
        for (int i=1; i<=i1; ++i) {
            for (int j=1; j<=j2; ++j) {
                for (int k=1; k<=i2; ++k) {
                    ans_mat[i][j]+=mat1[i][k]*mat2[k][j];
                }
            }
        }
    }
    print(ans_mat, i1, j2);
}
