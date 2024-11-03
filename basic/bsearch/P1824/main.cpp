#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int n, c;
// 判断距离x是否可行
bool p(int x) {
    int a_c=0, last = arr[1];
    for (int i=2; i<=n; ++i) {
        if (arr[i]-last>=x) {
            ++a_c;
            last = arr[i];
        }
    }
    return a_c+1 >= c;
}
int main() {
    scanf("%d%d", &n, &c);
    for (int i=1; i<=n; ++i)
        scanf("%d", &arr[i]);
    sort(arr+1, arr+1+n);
    int l=0, r=1000000000;
    int ans;
    while (l<=r) {
        int mid=(l+r)/2;
        if (p(mid)) {
            ans = mid;
            l = mid+1;
        } else {
            r = mid - 1;
        }
    }
    printf("%d", ans);
    return 0;
}

