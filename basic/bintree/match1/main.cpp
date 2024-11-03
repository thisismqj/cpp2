#include <bits/stdc++.h>
using namespace std;
int n;
int val[260];
int winner[260];
void dfs(int x) {
    if (x>=1<<n) return;
    else {
        dfs(2*x);
        dfs(2*x+1);
        if (val[2*x]>val[2*x+1]) {
            val[x] = val[2*x];
            winner[x] = winner[2*x];
        } else {
            val[x] = val[2*x+1];
            winner[x] = winner[2*x+1];
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i=1<<n;i<=1<<(n+1)-1;++i) {
        scanf("%d", &val[i]);
        winner[i] = i-(1<<n)+1;
    }
    dfs(1);
    printf("%d", val[2]>val[3]?winner[2]:winner[3]);
    return 0;
}
