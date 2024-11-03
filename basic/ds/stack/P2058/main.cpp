#include <bits/stdc++.h>
using namespace std;
int n;
struct Pas {
    int t;
    int c;
};
int vis[100005];
queue<Pas> Q;
int main() {
    scanf("%d", &n);
    int ans=0;
    for (int i=1; i<=n; ++i) {
        int t;
        scanf("%d", &t);
        int nn;
        scanf("%d", &nn);
        for (int j=1; j<=nn; ++j) {
            int c;
            scanf("%d", &c);
            Q.push(Pas{t, c});
            if (vis[c]==0) ++ans;
            vis[c]++;
        }
        Pas h = Q.front();
        while (h.t+86400<=t) {
            Q.pop();
            --vis[h.c];
            if (vis[h.c]==0) --ans;
            h = Q.front();
        }
        printf("%d\n", ans);
    }
    return 0;
}