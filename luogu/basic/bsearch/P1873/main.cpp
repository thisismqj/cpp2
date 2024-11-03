#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull n, m;
int arr[1000005];
bool p(int x) {
    ull woods=0;
    for (int i=1; i<=n; ++i) {
        if (x < arr[i]) woods += arr[i] - x;
    }
    return woods>=m;
}
int main() {
    scanf("%llu%llu", &n, &m);
    for (int i=1; i<=n; ++i)
        scanf("%d", &arr[i]);
    sort(arr+1, arr+1+n);
    int l=0, r=arr[n];
    int ans;
    while (l<=r) {
        int mid=(l+r)/2;
        if (p(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    printf("%d", ans);
    return 0;
}

