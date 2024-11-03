#include <bits/stdc++.h>
using namespace std;
int len, n, m;
int stones[50005];
bool p(int x) {
    int last = 0;
    int _m = m;
    for (int i=1; i<=n; ++i) {
        int dist = stones[i]-last;
        if (dist>=x) {
            last = stones[i];
        } else {
            // 拆石头
            --_m;
        }
    }
    if (len - last < x) --_m;
    return _m>=0;
}
int main() {
    // len: 端长度 n: 石头数 m: 移走数
    scanf("%d%d%d", &len, &n, &m);
    for (int i=1; i<=n; ++i)
        scanf("%d", &stones[i]);
    int ans;
    int r=len+1;
    if (n!=m)
        r = len/(n-m) + 1;
    int l = 1;
    while (l<r) {
        int mid = l + (r-l)/2;
        if (p(mid)) l = mid+1;
        else r = mid;
    }
    --l;
    printf("%d", l);
    return 0;
}

