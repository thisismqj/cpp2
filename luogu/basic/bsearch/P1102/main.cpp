#include <bits/stdc++.h>
using namespace std;
int arr[200005];
int n, c;
int find_first(int x) {
    int l=1, r=n+1;
    while (l<r) {
        int mid = l + (r-l) / 2;
        if (x <= arr[mid]) r = mid;
        else l = mid+1;
    }
    if (x==arr[l]) return l;
    return -1;
}
int find_last(int x) {
    int l=1, r=n+1;
    while (l<r) {
        int mid = l + (r-l) / 2;
        if (x >= arr[mid]) l = mid+1;
        else r = mid;
    }
    if (x==arr[l-1]) return l-1;
    return -1;
}
int main() {
    scanf("%d%d", &n, &c);
    for (int i=1; i<=n; ++i) {
        scanf("%d", &arr[i]);
    }
    sort(arr+1, arr+1+n);
    unsigned long long result = 0;
    for (int i=1; i<=n; ++i) {
        int target = arr[i]-c;
        int l = find_first(target);
        if (l==-1) continue;
        int r = find_last(target);
        result += r-l+1;
    }
    printf("%llu", result);
}

