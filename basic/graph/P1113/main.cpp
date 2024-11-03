#include <bits/stdc++.h>
using namespace std;
int T[10005];
vector<int> father[10005];
int t[10005];
int dfs(int n) {
    int max_T = 0;
    for (int sn:father[n]) {
        max_T = max(max_T, T[sn]);
    }
    max_T+=t[n];
    return T[n] = max_T;
}
int n;
int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; ++i) {
        int tm;
        scanf("%d", &tm);
        scanf("%d", &tm);
        t[i] = tm;
        while (true) {
            int x;
            scanf("%d", &x);
            if (x==0) break;
            father[i].push_back(x);
        }
        dfs(i);
    }
    int max_T=0;
    for (int i=1; i<=n; ++i) {
        max_T = max(max_T, T[i]);
    }
    printf("%d", max_T);
    return 0;
}
