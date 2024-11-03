#include <bits/stdc++.h>
using namespace std;
int n, k; // 原木数， 小段数
int arr[100005];
bool p(int l) { // l长度可切出>=k段
    int cnt = 0;
    for (int i=1;i<=n;++i) {
        int h = arr[i];
        cnt += h / l;
    }
    return cnt >= k;
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i=1;i<=n;++i)
        scanf("%d", &arr[i]);
    int l=1, r=100000001;
    while (l<r) {
        int mid = l+(r-l)/2;
        if (p(mid)) l = mid +1;
        else r = mid;
    }
    --l;
    if (l==0) {
        putchar('0');
        return 0;
    } else {
        printf("%d", l);
    }
    return 0;
}

