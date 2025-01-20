#include <bits/stdc++.h>
using namespace std;
int n, m, k;
struct T {int v, c;} t[100005];
bool cmp(T &a, T &b) {
    if (a.v!=b.v) {
        return a.v>b.v;
    } else {
        return a.c<b.c;
    }
}
int main() {
    cin>>n>>m>>k;
    for (int i=1; i<=n; ++i)
        cin>>t[i].v>>t[i].c;
    sort(t+1, t+1+n, cmp);
    while (m>0&&t[1].v>k) {
        m-=t[1].c;
        if (m<0) break;
        t[1].v--;
        if (t[1].v<t[2].v) {
            int i=2;
            while (t[i].v>t[1].v) ++i;
            // [_tp, i-1] exchange
            T tmp = t[1];
            for (int j=2; j<i; ++j) {
                t[j-1] = t[j];
            }
            t[i-1] = tmp;
        } else if (t[1].v==t[2].v) {
            int i=2;
            while (t[i].v==t[1].v&&t[i].c<t[1].c&&i<=n) ++i;
            T tmp=t[1];
            for (int j=2; j<i; ++j) {
                t[j-1] = t[j];
            }
            t[i-1] = tmp;
        }
    }
    cout<<max(t[1].v, k);
    return 0;
}

