#include <bits/stdc++.h>
using namespace std;
int len;  // 路长
int n;  // 路标数
int k;  // 增设路标数
int boards[100005];
bool p(int x) { // 达到空旷程度<=x需要<=k个路标
    // xxxxxxvvvv
    int cnt = 0;
    for (int i=1; i<=n+1; ++i) {
        int d = boards[i] - boards[i-1];
        cnt += (d-1)/x;
    }
    return cnt<=k;
}
int main() {
    scanf("%d%d%d", &len, &n, &k);
    for (int i=1; i<=n; ++i)
        scanf("%d", &boards[i]);
    boards[n+1] = len;
    int l = 1, r = len;
    while (l<r) {
        int mid = l + (r-l)/2;
        if (p(mid)) r = mid;
        else l = mid+1;
    }
    printf("%d", l);
    return 0;
}

