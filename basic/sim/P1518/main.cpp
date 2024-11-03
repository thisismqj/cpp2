#include <bits/stdc++.h>
using namespace std;
char m[12][12];
char mv_x[4] = {-1, 0, 1, 0};
char mv_y[4] = {0, 1, 0, -1};

struct S {
    int x;
    int y;
    int dir=0;// ^: 0 >: 1 v: 2 <: 3
    inline bool operator==(const S &d) {
        return (x==d.x&&y==d.y&&dir==d.dir);
    }
} farmer, cow, f, c;

int main() {
    int t=1;
    for (int i=1; i<=10; ++i)
        for (int j=1; j<=10;++j){
            cin>>m[i][j];
            // init f & c
            if (m[i][j]=='F') {
                farmer.x = i;
                farmer.y = j;
                m[i][j]='.';
            }
            if (m[i][j]=='C') {
                cow.x = i;
                cow.y = j;
                m[i][j]='.';
            }
        }
    f.x=farmer.x, f.y=farmer.y, c.x=cow.x, c.y=cow.y;
    while (t<=10000 && (t==1||!(f==farmer&&c==cow))) { // cout + return
        f.x += mv_x[f.dir];
        f.y += mv_y[f.dir];
        c.x += mv_x[c.dir];
        c.y += mv_y[c.dir];
        if (m[f.x][f.y]==0 || m[f.x][f.y]=='*') {
            f.x -= mv_x[f.dir];
            f.y -= mv_y[f.dir];
            ++f.dir, f.dir%=4;
        }
        if (m[c.x][c.y]==0 || m[c.x][c.y]=='*') {
            c.x -= mv_x[c.dir];
            c.y -= mv_y[c.dir];
            ++c.dir, c.dir%=4;
        }
        if (f.x==c.x&&f.y==c.y) {
            cout << t;
            return 0;
        }
        ++t;
    }
    cout << 0;
}

