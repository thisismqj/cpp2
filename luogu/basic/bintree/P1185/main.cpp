#include <bits/stdc++.h>
using namespace std;
bool t[2060];
char scr[800][1600];
struct Pos {int x, y;} t2pos[1030];
int m, n;
void del(int rt) {
    if (t[rt]) {
        t[rt]=false;
        del(2*rt);
        del(2*rt+1);
    }
}
void connect(int n1, int n2) {
    Pos p1 = t2pos[n1], p2 = t2pos[n2];
    int y3=(p1.y+p2.y)/2;
    int x3=p1.x+(y3-p1.y);
    t2pos[n1/2] = {x3, y3};
    if (t[n1/2]) {
        scr[x3][y3] = 'o';
        for (int i=1; i<(x3-p1.x);++i) {
            if (t[n1])
                scr[x3-i][y3-i] = '/';
            if (t[n2])
                scr[x3-i][y3+i] = '\\';
        }
    }
}
int main() {
    scanf("%d%d", &m, &n);
    memset(t, 1, 1<<m);
    memset(scr, ' ', sizeof(scr));
    for (int k=1; k<=n; ++k) {
        int i, j;
        scanf("%d%d", &i, &j);
        del((1<<(i-1))+j-1);
    }
    bool t3=true;
    int x0=1;
    for (int i=(1<<(m-1))+1-1; i<=(1<<(m-1))+(1<<(m-1))-1; ++i) {
        t2pos[i] = {1, x0};
        if (t[i]) {
            scr[1][x0] = 'o';
        }
        if (t3) {
            t3=false;
            x0+=4;
        } else {
            t3=true;
            x0+=2;
        }
    }
    for (int i=m-1; i>=1; --i) {
        for (int j=1; j<=(1<<(i-1)); ++j) {
            int rt = (1<<(i-1))+j-1;
            connect(2*rt, 2*rt+1);
        }
    }
    for (int i=3*(1<<(m-2)); i>=1; --i) {
        for (int j=1; j<=3*(1<<(m-1))-1; ++j) {
            putchar(scr[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
