#include <bits/stdc++.h>
using namespace std;
int n;
int arr[305];
int main() {
    scanf("%d", &n);
    for (int i=1;i<=n;++i) {
        scanf("%d", &arr[i]);
    }
    sort(arr+1, arr+n+1);
    unsigned long long power=0;
    int i=0,j=n;
    while (i<j) {
        power+=(arr[j]-arr[i])*(arr[j]-arr[i]);
        ++i;
        power+=(arr[j]-arr[i])*(arr[j]-arr[i]);
        --j;
    }
    printf("%llu", power);
}

