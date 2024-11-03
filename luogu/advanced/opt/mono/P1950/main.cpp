#include <bits/stdc++.h>
using namespace std;
// calc h_i
// initally its height
// iter from top to down
// if up(if have) isn't star, make it its up h
// calc l_i
// a stack of indexes of the left()
// maintain an increasing stack, when push, pop until h[top] <= h[i], l = h[top], push i
char cmap[1005][1005];
int lst[1005];
int _lp=0;
int rst[1005];
int _rp=0;
struct Data {
    int h, l, r, hl, hr;
} dmap[1005][1005];
inline unsigned long long calc(int i, int j) {
    // ans = (j-l[i][j])*(r[i][j]-j)*h[i][j]
    return (j-dmap[i][j].l)*(dmap[i][j].r-j)*(dmap[i][j].h);
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    unsigned long long ans = 0;
    for (int i=1; i<=n; ++i) {
        _lp = 0;
        for (int j=1; j<=m; ++j) {
            cin >> cmap[i][j];
            if (cmap[i][j]!='*') {
                dmap[i][j].hl = j;
                dmap[i][j].h = 1;
                if (j>1&&cmap[i][j-1]!='*') dmap[i][j].hl = dmap[i][j-1].hl;
                if (i>1&&cmap[i-1][j]!='*') {
                    dmap[i][j].h = dmap[i-1][j].h+1;
                }
                while (_lp>0&&dmap[i][lst[_lp-1]].h>dmap[i][j].h) --_lp;
                if (_lp>0)
                    dmap[i][j].l = lst[_lp-1];
                else
                    dmap[i][j].l = dmap[i][j].hl-1;
                lst[_lp++] = j;
            } else _lp = 0;
        }
        _rp = 0;
        for (int j=m; j>=1; --j) {
            if (cmap[i][j]!='*') {
                dmap[i][j].hr = j;
                if (j<m&&cmap[i][j+1]!='*') dmap[i][j].hr = dmap[i][j+1].hr;
                while (_rp>0&&dmap[i][rst[_rp-1]].h>=dmap[i][j].h) --_rp;
                if (_rp>0)
                    dmap[i][j].r = rst[_rp-1];
                else
                    dmap[i][j].r = dmap[i][j].hr+1;
                rst[_rp++] = j;
            } else _rp = 0;
        }
    }
    // Debug
    // for (int i=1; i<=n; ++i) {
    //     for (int j=1; j<=m; ++j) {
    //         printf("%d-%d-%d\t", dmap[i][j].h, dmap[i][j].l, dmap[i][j].r);
    //     }
    //     putchar('\n');
    // }
    //
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j) {
            if (cmap[i][j]!='*') ans+=calc(i, j);
        }
    }
    printf("%llu", ans);
    return 0;
}
