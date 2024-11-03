#include <bits/stdc++.h>
using namespace std;
int f[1005];
int main() {
    int n;
    scanf("%d", &n);
    f[1] = 1;
    for (int i=2; i<=n; ++i) {
        int sum=1;
        for (int j=i/2; j>=1; --j) {
            sum += f[j];
        }
        f[i] = sum;
    }
    printf("%d", f[n]);
}

