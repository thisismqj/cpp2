#include <bits/stdc++.h>
using namespace std;
// A = w*h
// w: the narrowest of it and its up
// l: initally itself. if left isn't a R, then make it left value
// r: initally W - l + 1. if right isn't a R, then make it right value
// h: initlally 1. if up isn't a R, make it up + 1
struct Data {
    int l, r, h;
} dmap[1005][1005];
char cmap[1005][1005];
int main() {
    // init
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j) {
            cin>>cmap[i][j];
            dmap[i][j].h = 1;
            dmap[i][j].l = j;
            dmap[i][j].r = j;
        }
    }
    //
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j) {
            if (i>1&&cmap[i-1][j]!='R') dmap[i][j].h = dmap[i-1][j].h+1;
            if (j>1&&cmap[i][j-1]!='R') dmap[i][j].l = dmap[i][j-1].l;
            if (m-j+1<m&&cmap[i][m-j+1+1]!='R') dmap[i][m-j+1].r = dmap[i][m-j+1+1].r;
        }
    }
    int max_area = 0;
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j) {
            if (cmap[i][j]!= 'R') {
                int l = dmap[i][j].l, r = dmap[i][j].r;
                for (int ii = i-1; ii>=1&&cmap[ii][j]!='R'; --ii) {
                    l = max(l, dmap[ii][j].l);
                    r = min(r, dmap[ii][j].r);
                }
                int area = (r-l+1) * dmap[i][j].h;
                max_area = max(max_area, area);
            }
        }
    }
    printf("%d", 3*max_area);
    return 0;
}
