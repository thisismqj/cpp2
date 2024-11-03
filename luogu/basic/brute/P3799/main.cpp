#include <bits/stdc++.h>
using namespace std;
int bucket[5005];
int main() {
    int n;
    scanf("%d", &n);
    if (n<4) {
        putchar('0');
        return 0;
    }
    for (int i=0; i<n; ++i) {
        int inp;
        scanf("%d", &inp);
        bucket[inp]++;
    }
    unsigned long long ans=0;
    for (int i=1; i<=5000; ++i) {
        if (bucket[i]>=2) {
            int combine = bucket[i] * (bucket[i]-1) /2;
            unsigned long long sum = 0;
            for (int j=i-1; j>i/2; --j) {
                sum += bucket[j] * bucket[i-j];
            }
            if (i%2==0) {
                sum+=bucket[i/2] * (bucket[i/2]-1) /2;
            }
            ans += sum * combine;
        }
    }
    ans%=1000000007;
    printf("%d", ans);
}

