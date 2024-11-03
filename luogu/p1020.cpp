#include <bits/stdc++.h>
using namespace std;
int st[100005];
int _p=0;
int arr[100005];
int dp[100005];
int f[100005];
int l=1;
int main() {
    int x;
    while (scanf("%d", &x)!=EOF) {
        bool hasm=false;
        for (int i=0; i<=_p-1; ++i) {
            if (st[i]>=x) {
                hasm=true;
                st[i] = x;
                break;
            }
        }
        if (!hasm) {
            st[_p++] = x;
        }
        arr[l++]=x;
    }
    --l;
    dp[1] = 1;
    f[1] = arr[1];
    int maxl = 1;
    for (int i=2; i<=l; ++i) {
        // search max len, f[len] >= arr[i], f[len] down
        int l = 1, r = maxl+1;
        while (l<r) {
            int mid = (l+r) /2;
            if (f[mid] >= arr[i])
                l = mid+1;
            else r = mid;
        }
        dp[i] = 1+l-1;
        if (dp[i] > maxl) maxl = dp[i];
        if (f[dp[i]] < arr[i]) f[dp[i]] = arr[i];
    }
    printf("%d\n%d", maxl, _p);
    return 0;
}
