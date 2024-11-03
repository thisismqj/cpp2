#include <bits/stdc++.h>
using namespace std;
int dctrl[9][2] = {{0,0},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},
{-1,-2},{-2,-1}};
// dp[i][j]: 从(0,0)到(i,j)路径数
unsigned long long dp[100][25];
bool ctrl[100][25];
int main() {
    int n, m;
    int hx, hy;
    scanf("%d%d%d%d", &n,&m,&hx,&hy);
    for (int i=0; i<9; ++i) {
        if (hx+dctrl[i][0]+1>=1 && hx+dctrl[i][0]+1<=n+1 
        && hy+dctrl[i][1]+1>=1 && hy+dctrl[i][1]+1<=m+1)
            ctrl[hx+dctrl[i][0]+1][hy+dctrl[i][1]+1]=1;
    }
    if (ctrl[1][1]==1) dp[1][1]=0;
    else dp[1][1]=1;
    for (int i=1; i<=n+1; ++i)
        for (int j=1; j<=m+1; ++j) {
            if (ctrl[i][j]) continue;
            dp[i][j]+=dp[i-1][j];
            dp[i][j]+=dp[i][j-1];
        }
    printf("%llu", dp[n+1][m+1]);
}

