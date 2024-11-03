#include <bits/stdc++.h>
using namespace std;
bool isPrime(int i) {
    for (int j=2; j*j<=i; ++j) {
        if (i%j==0) return false;
    }
    return true;
}
int inputs[20];
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i=0; i<n; ++i) {
        scanf("%d", &inputs[i]);
    }
    unsigned bin;
    int types=0;
    for (bin=(1<<(k))-1; bin < (1<<(n)); ++bin) {
        if (__popcount(bin)==k) {
            int sum=0;
            for (unsigned j=0; j<n; ++j) {
                if (bin & 1<<j) {
                    sum+=inputs[j];
                }
            }
            if (isPrime(sum)) ++types;
        }
    }
    printf("%d", types);
}

