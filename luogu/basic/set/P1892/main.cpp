#include <bits/stdc++.h>
using namespace std;
int nxt[1005], enm[1005];
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

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; ++i) nxt[i] = i;
    for (int i=1; i<=m; ++i) {
        char opt; int p, q;
        scanf("\n%c", &opt);
        scanf("%d%d", &p, &q);
        if (opt=='F') {
            if (!same_set(p, q)) {
                cmb(p, q);
                --n;
            }
        } else {
            if (!enm[p]) {
                enm[p] = q;
            } else {
                if (!same_set(enm[p], q)) {
                    cmb(enm[p], q);
                    --n;
                }
            }
            if (!enm[q]) {
                enm[q] = p;
            } else {
                if (!same_set(enm[q], p)) {
                    cmb(enm[q], p);
                    --n;
                }
            }
        }
    }
    printf("%d", n);
    return 0;
}
