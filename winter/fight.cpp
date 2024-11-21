#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt[100005], l_air, r_air;
int n;
int main() {
    cin>>n;
    for (int i=1; i<=n; ++i) cin>>cnt[i];
    int m, p1, s1, s2;
    cin>>m>>p1>>s1>>s2;
    cnt[p1]+=s1;
    for (int i=1; i<m; ++i) {
        l_air+=(m-i)*cnt[i];
    }
    for (int i=m+1; i<=n; ++i) {
        r_air+=(i-m)*cnt[i];
    }
    ll dif = l_air-r_air;
    ll dif_min = LONG_LONG_MAX;
    int ans;
    for (int i=n; i>=1; --i) {
        if (i==m) continue;
        if (llabs(dif-s2*(i-m)<=dif_min)) {
            dif_min = llabs(dif-s2*(i-m));
            ans = i;
        }
    }
    cout<<ans;
    return 0;
}
