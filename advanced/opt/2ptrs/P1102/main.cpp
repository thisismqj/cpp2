#include <bits/stdc++.h>
using namespace std;
int n, c;
int p1=1, p2=1;
int arr[200005];
int main() {
    scanf("%d%d", &n, &c);
    for (int i=1; i<=n; ++i) {
        scanf("%d", &arr[i]);
    }
    sort(arr+1, arr+1+n);
    unsigned long long ans=0;
    for (int i=1; i<=n; ++i) {
        int x=arr[i];
        while (arr[p1]<x-c) ++p1;
        while (arr[p2]<=x-c&&p2<=n) ++p2;
        ans+=p2-p1;
    }
    printf("%llu", ans);
    return 0;
}
