#include <bits/stdc++.h>
using namespace std;
int cows[20000];
int main() {
    int n, b, sum=0, i=0;
    scanf("%d %d", &n, &b);
    for (int i=0; i<n; ++i)
        scanf("%d", &cows[i]);
    sort(cows, cows+n);
    for (i=1; ; ++i) {
        sum += cows[n-i];
        if (sum >= b) break;
    }
    printf("%d", i);
}

