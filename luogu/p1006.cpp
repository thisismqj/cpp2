#include <bits/stdc++.h>
using namespace std;
int f[55][55][55][55];  // f(x1, y1)(x2, y2)表示走到此两点时的好心程度和
int arr[55][55];
int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    // f[x1][y1][x2][y2] = arr[x1][y1]+arr[x2][y2]((x1, x2)不等) + max{,,,}
    // 路径不能交叉
        // 将交叉状态置0? 交叉状态没有子节点且一定为0
        // 如果不是交叉状态，那么其父也不是
    for (int i=1; i<=m; ++i) {
        for (int j=1; j<=n; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int x1=1; x1<=m; ++x1) {
        for (int y1=1; y1<=n; ++y1) {
            for (int x2=1; x2<=m; ++x2) {
                for (int y2=1; y2<=n; ++y2) {
                    if (!(x1==x2&&y1==y2)) {
                        f[x1][y1][x2][y2] = arr[x1][y1]+arr[x2][y2]+
                        max(
                        max(f[x1-1][y1][x2-1][y2],f[x1-1][y1][x2][y2-1]),
                        max(f[x1][y1-1][x2-1][y2],f[x1][y1-1][x2][y2-1]));
                    }
                }
            }
        }
    }
    f[m][n][m][n] = max(f[m-1][n][m][n-1],f[m][n-1][m-1][n]);
    printf("%d", f[m][n][m][n]);
    return 0;
}

