#include <bits/stdc++.h>
using namespace std;
// fl=fn=a[1], 然后fn推进, fn = max{fl, fl+an}, 直到fn到n, 每次推进记录最大值
int arr[200005];
int main() {
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; ++i)
        scanf("%d", &arr[i]);
    int fn, fl=0;
    int maxn = INT_MIN;
    for (int i=1; i<=n; ++i) {
        fn = max(arr[i], fl+arr[i]);
        maxn = max(fn, maxn);
        fl = fn;
    }
    printf("%d", maxn);
    return 0;
}
