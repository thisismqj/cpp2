#include <bits/stdc++.h>
using namespace std;
int f[205][205]; // f[i][j]表示将[i:j]合并为一颗珠子释放的最大能量值
int s[205]; // 珠子能量值
int n;
int main() {
    cin>>n;
    for (int i=1; i<=n; ++i) {
        cin>>s[i]; s[n+i] = s[i];
    }
    int ans=0;
    for (int l=2; l<=n; ++l) {
        for (int i=1; i<=2*n-l; ++i) {
            int j=i+l-1;
            for (int k=i; k<=j-1; ++k) {
                f[i][j] = max(f[i][j], f[i][k]+f[k+1][j]+s[i]*s[k+1]*s[j+1]);
            }
            ans=max(ans, f[i][i+l-1]);
        }
    }
    cout<<ans;
}
