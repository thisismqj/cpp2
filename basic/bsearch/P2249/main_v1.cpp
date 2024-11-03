#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[1000005];
int find(int x) {
    int l=1, r=n;
    while (l<=r) {
        int mid = (l+r)/2;
        if (arr[mid]>=x) r = mid-1;
        else l = mid+1;
    }
    if (arr[l]==x) return l;
    return -1;
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

