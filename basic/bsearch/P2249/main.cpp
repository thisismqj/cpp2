#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[1000005];
// y >= x则返回true
inline bool p(int x, int y) {
    return y>=x;
}
int find(int x) {
    int l=1, r=n;
    int ans;
    while (l<=r) {
        int mid = (l+r) / 2;
        if (p(x, mid)) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    return ans;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; ++i) {
        scanf("%d", &arr[i]);
    }
    int x;
    while (scanf("%d", &x) != EOF) {
        printf("%d ", find(x));
    }
}

