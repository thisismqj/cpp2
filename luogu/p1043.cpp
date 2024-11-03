#include <bits/stdc++.h>
using namespace std;
// 对10取模预处理
// 区间dp?
// 环展开成链
// f[i][j]特别处理??
// f[i][j][k] 表示 [i:j]切k段的最大值
// f[i][j][k] = max{f[i][j-x][k-1]*f[j-x+1][j][0]}
// ans = max{f[i][i-1][m-1](i!=1), f[1][n][m-1]}
int f[51][51][10];
int g[51][51][10];
int arr[51];// 环(预处理过
int n, m;
inline int mod10(int x) {
    return x>=0?x%10:x%10+10;
}
int main() {
    // g初始化
    memset(g, 0x7F, sizeof(g));
    cin>>n>>m;
    for (int i=1; i<=n; ++i) {
        int x;
        cin>>x;
        arr[i] = mod10(x);
    }
    // 初始化f[i][j][0]
    for (int i=1; i<=n; ++i) {
        for (int j=i; j<=n; ++j) {
            if (i==j) {g[i][j][0]=f[i][j][0] = arr[i];}
            else {
                g[i][j][0]=f[i][j][0] = (f[i][j-1][0]+arr[j])%10;
            }
        }
    }
    for (int i=2; i<=n; ++i) {
        for (int j=i-1; j>=1; --j) {
            g[i][j][0]=f[i][j][0] = (f[i][n][0] + f[1][j][0])%10;
        }
    }
    // dp开始
    for (int k=1; k<=m-1; ++k) {
        for (int i=1; i<=n-1; ++i) {
            for (int j=i+1; j<=n; ++j) {
                for (int x=i+k-1; x<=j-1; ++x) {
                    f[i][j][k] = max(f[i][j][k], f[i][x][k-1]*f[x+1][j][0]);
                }
            }
        }
        for (int i=2; i<=n; ++i) {
            for (int j=i-1; j>=1; --j) {
                for (int x=i+k-1; x<=n; ++x) {
                    f[i][j][k] = max(f[i][j][k], f[i][x][k-1]*f[x+1<=n?x+1:1][j][0]);
                }
                for (int x=max(1, i+k-1-n); x<=j; ++x) {
                    f[i][j][k] = max(f[i][j][k], f[i][x][k-1]*f[x+1][j][0]);
                }
            }
        }
    }
    for (int k=1; k<=m-1; ++k) {
        for (int i=1; i<=n-1; ++i) {
            for (int j=i+1; j<=n; ++j) {
                for (int x=i+k-1; x<=j-1; ++x) {
                    g[i][j][k] = min(g[i][j][k], g[i][x][k-1]*f[x+1][j][0]);
                }
            }
        }
        for (int i=2; i<=n; ++i) {
            for (int j=i-1; j>=1; --j) {
                for (int x=i+k-1; x<=n; ++x) {
                    g[i][j][k] = min(g[i][j][k], g[i][x][k-1]*f[x+1<=n?x+1:1][j][0]);
                }
                for (int x=max(1, i+k-1-n); x<=j-1; ++x) {
                    g[i][j][k] = min(g[i][j][k], g[i][x][k-1]*f[x+1][j][0]);
                }
            }
        }
    }
    // dp结束
    int ans=g[1][n][m-1];
    for (int i=2; i<=n; ++i) {
        ans = min(ans, g[i][i-1][m-1]);
    }
    cout<<ans<<endl;
    ans=f[1][n][m-1];
    for (int i=2; i<=n; ++i) {
        ans = max(ans, f[i][i-1][m-1]);
    }
    cout<<ans;
}
