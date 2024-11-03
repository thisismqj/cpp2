#include <bits/stdc++.h>
using namespace std;
// f(n) = sigma( f(k-1) * f(n-k) ) k in [1, n]
int dp[19];
int main() {
    int n;
    scanf("%d", &n);
    dp[0]=1;
    dp[1]=1;
    for (int i=2; i<=n; ++i) {
        for (int k=1; k<=i; ++k) {
            dp[i] +=dp[k-1]*dp[i-k];
        }
    }
    printf("%d", dp[n]);
}

