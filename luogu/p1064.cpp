#include <bits/stdc++.h>
using namespace std;
int f[3205]; // f[i]: i元的最大满意程度(价值)
int main_p[65], main_v[65]; // 主件价格和价值(0)则非主件
int annex_p[65][3], annex_v[65][3]; // 附件价格, 价值(0维表示附件个数)
int n, m;// 拥有的钱, 件数
int main() {
    cin>>n>>m;
    n/=10;
    for (int i=1; i<=m; ++i) {
        int a, b, c;// 价格 重要度 所属
        cin>>a>>b>>c;
        a/=10;
        if (c==0) {
            main_p[i] = a;
            main_v[i] = a*b;
        } else {
            int cnt=++annex_v[c][0];
            annex_p[c][cnt] = a;
            annex_v[c][cnt] = a*b;
        }
    }
    for (int j=1; j<=m; ++j) {
        if (main_v[j]) {
            for (int i=n; i>=1; --i) {
                if (i>=main_p[j]) {
                    // 仅主件
                    f[i] = max(f[i], f[i-main_p[j]]+main_v[j]);
                    // 主+1
                    if (annex_v[j][0]>=1&&i>=main_p[j]+annex_p[j][1])
                        f[i] = max(f[i], f[i-main_p[j]-annex_p[j][1]]+main_v[j]+annex_v[j][1]);
                    // 主+2
                    if (annex_v[j][0]>=2&&i>=main_p[j]+annex_p[j][2])
                        f[i] = max(f[i], f[i-main_p[j]-annex_p[j][2]]+main_v[j]+annex_v[j][2]);
                    // 主+12
                    if (annex_v[j][0]>=2&&i>=main_p[j]+annex_p[j][2]+annex_p[j][1])
                        f[i] = max(f[i], f[i-main_p[j]-annex_p[j][2]-annex_p[j][1]]+main_v[j]+annex_v[j][2]+annex_v[j][1]);
                }
            }
        }
    }
    cout<<f[n]*10;
}
