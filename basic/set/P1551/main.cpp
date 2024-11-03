#include <bits/stdc++.h>
using namespace std;
int nxt[5005];
int n, m, p;
int find_head(int node) {
    if (nxt[node]==node) return node;
    else return nxt[node] = find_head(nxt[node]);
}
int main() {
    scanf("%d%d%d", &n, &m, &p);
    // init
    for (int i=1; i<=n; ++i)
        nxt[i] = i;
    for (int i=1; i<=m; ++i) {
        int m1, m2;
        scanf("%d%d", &m1, &m2);
        int h1=find_head(m1), h2=find_head(m2);
        if (h1!=h2) {
            nxt[h1]=h2;
        }
    }
    for (int i=1; i<=p; ++i) {
        int m1, m2;
        scanf("%d%d", &m1, &m2);
        if (find_head(m1)==find_head(m2)) {
            printf("Yes\n");
        } else printf("No\n");
    }
    return 0;
}
