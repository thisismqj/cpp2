#include <bits/stdc++.h>
using namespace std;
struct Boat {
    int t;
    int max_c;
    bool *c;
} Boats[100005];
struct Q {
    int vis[100005];
    int q[100005];
    int head=1;
    int tail=1;
    int max_c;
    void push(int i) {
        if (Boats[i].max_c > max_c) max_c = Boats[i].max_c;
        q[tail++] = i;
        for (int j=1; j<=Boats[i].max_c; ++j) {
            vis[j]+=Boats[i].c[j];
        }
    }
    void pop() {
        int p=q[head];
        for (int j=1; j<=Boats[p].max_c; ++j) {
            vis[j] -= Boats[p].c[j];
        }
        free(Boats[p].c);
        q[head] = 0;
        head++;
    }
    int count() {
        int result=0;
        for (int i=1; i<=max_c; ++i) {
            if (vis[i]) ++result;
        }
        return result;
    }
} que;
int n;
int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; ++i) {
        int nn;
        scanf("%d%d", &Boats[i].t, &nn);
        int nmax=0;
        for (int j=1;j<=nn;++j) {
            int cc;
            scanf("%d", &cc);
            if (cc>nmax) {
                Boats[i].c = (bool *)realloc(Boats[i].c, cc+1);
                nmax = cc;
            }
            Boats[i].c[cc] = true;
        }
        Boats[i].max_c = nmax;
    }
    for (int i=1; i<=n; ++i) {
        que.push(i);
        for (int j=que.head; Boats[que.q[j]].t+86400<=Boats[i].t; ++j) {
            que.pop();
        }
        printf("%d\n", que.count());
    }
    return 0;
}
