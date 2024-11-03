#include <bits/stdc++.h>
using namespace std;
int main() {
    unsigned long long n, m;
    scanf("%llu %llu", &n, &m);
    unsigned long long rect = n*(n+1)*m*(m+1)/4;
    unsigned long long square = 0;
    for (int a=1; a<=min(n, m); ++a) {
        square += (n-a+1) * (m-a+1);
    }
    printf("%llu %llu", square, rect-square);
}

