#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[100005];
// 长度
bool p(int x) {
    int sum=0, cnt=0;
    for (int i=1; i<=n; ++i) {
        if (arr[i]>x) return false;
        sum+=arr[i];
        if (sum>x) {
            sum = arr[i];
            ++cnt;
        }
    }
    if (sum <=x) ++cnt;
    return cnt <= m;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n;++i) {
        scanf("%d", &arr[i]);
    }
    int l=1, r=1000000001;
    while (l<r) {
        int mid = l+ (r-l)/2;
        if (p(mid)) r = mid;
        else l = mid+1;
    }
    printf("%d", l);
    return 0;
}

