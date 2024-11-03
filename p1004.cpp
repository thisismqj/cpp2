#include <bits/stdc++.h>
using namespace std;
// dp
// f[x1][y1][x2][y2]表示第一次走(x1, y1), 第二次走(x2, y2)
int arr[12][12];
int f[12][12][12][12];
int n;
int main() {
    cin>>n;
    for (;;) {
        int x, y, c;
        cin>>x>>y>>c;
        if (x==0&&y==0&&c==0) break;
        arr[x][y] = c;
    }
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            for (int k=1; k<=n; ++k) {
                for (int l=1; l<=n; ++l) {
                    f[i][j][k][l] = arr[i][j] + (!((i==k)&&(j==l)))*arr[k][l] +
                    max(max(f[i-1][j][k-1][l],
                    f[i-1][j][k][l-1]),
                    max(f[i][j-1][k-1][l],
                    f[i][j-1][k][l-1]));
                }
            }
        }
    }
    cout<<f[n][n][n][n];
    return 0;
}
