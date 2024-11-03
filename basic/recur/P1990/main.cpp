#include <bits/stdc++.h>
using namespace std;
#define f(x,y) g[x][x-(y)]
int g[1000005][2] = {{0, 0},{1, 0},{2, 1}, {5, 2}}; // f(n, n) = g(n, 0), f(n, n-1) = g(n, 1)
int main() {
    int n;
    scanf("%d", &n);
    for (int i=4; i<=n; ++i) {
        f(i, i) = (f(i-1, i-1) + 2 * f(i-1, i-2) + f(i-2, i-2))%10000;
        f(i, i-1) = (f(i-2, i-2) + f(i-1, i-2))%10000;
    }
    printf("%d", f(n, n));
}

