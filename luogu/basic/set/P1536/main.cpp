#include <bits/stdc++.h>
using namespace std;
int nxt[1005];
int find_head(int m) {
    if (m==nxt[m]) return m;
    else return nxt[m] = find_head(nxt[m]);
}
int main() {
    while (true) {
        int n, m;
        scanf("%d", &n);
        if (n==0) break;
        int blk=n;
        for (int i=1; i<=n; ++i)
            nxt[i] = i;
        scanf("%d", &m);
        for (int i=1; i<=m; ++i) {
            int m1, m2;
            scanf("%d%d", &m1, &m2);
            int h1 = find_head(m1), h2 = find_head(m2);
            if (h1!=h2) {
                --blk;
                nxt[h1] = h2;
            }
        }
        printf("%d\n", blk-1);
    }
    return 0;
}
