#include <bits/stdc++.h>
// 7 3
// 1 8 13
// MAX = 69
using namespace std;
const int c_max = 70;
const int dp_max = 400;
int dp[dp_max + 5];
int types[20] = {0, 1};
int ans_types[20];
int _p = 2;
int n, k;
int ans=0;
void dfs(int depth=2) {
    if (depth == k+1) {
        // deal with types[]
        memset(dp, 0x7f, sizeof(dp));
        int i;
        for (int i=1; i<=k; ++i) {
            dp[types[i]] = 1; // init
        }
        for (i=2; i<=dp_max; ++i) {
            for (int j=1; j<=k&&i-types[j] >=1; ++j) {
                dp[i] = min(dp[i], dp[i-types[j]] + 1);
            }
            if (dp[i] > n) break;
        }
        if (i-1>ans) {
            ans = i-1;
            for (int j=1; j<=k; ++j) {
                ans_types[j] = types[j];
            }
        }
    } else {
    // remain k-depth numbers
        for (int i=_p; i<=c_max-(k-depth); ++i) {
            types[depth] = i;
            ++_p;
            dfs(depth+1);
            --_p;
        }
    }
}
int main() {
    scanf("%d%d", &n, &k);
    dfs();
    for (int i=1; i<=k; ++i) {
        printf("%d ", ans_types[i]);
    }
    putchar('\n');
    printf("MAX=%d", ans);
    return 0;
}
