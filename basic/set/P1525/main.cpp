#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int n1, n2;
    int c;
    bool operator<(Edge& e2) {
        return c<e2.c;
    }
} edges[100005];
int nxt[20005], enm[20005];
int find_head(int n) {
    if (nxt[n]==n) return n;
    else return nxt[n] = find_head(nxt[n]);
}
inline bool same_set(int n1, int n2) {
    return find_head(n1)==find_head(n2);
}
void cmb(int n1, int n2) {
    nxt[find_head(n2)] = find_head(n1);
}
int n, m;
int main() {
    scanf("%d%d", &n, &m);
    for (int i=1; i<=m; ++i) {
        scanf("%d%d%d", &edges[i].n1, &edges[i].n2, &edges[i].c);
    }
    sort(edges+1, edges+m+1);
    for (int i=1; i<=n; ++i) {
        nxt[i] = i;
    }
    for (int i=m; i>=1; --i) {
        int n1 = edges[i].n1, n2 = edges[i].n2;
        if (same_set(n1, n2)) {
            printf("%d", edges[i].c);
            return 0;
        } else {
            if (enm[n1]) {
                // cmb n2 to enm[n1]
                cmb(enm[n1], n2);
            } else enm[n1] = n2;
            if (enm[n2]) {
                cmb(enm[n2], n1);
            } else enm[n2] = n1;
        }
    }
    printf("0");
    return 0;
}
