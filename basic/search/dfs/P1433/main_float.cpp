#include <bits/stdc++.h>
using namespace std;
struct Pos {float x, y;} cheeses[20];
int n;
float dis=0;
float state_min[1<<15][16];
inline float dist(Pos p1, Pos p2) {
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
unsigned state=0;
void dfs(int depth, int root) {
    if (dis > state_min[state][root]) {
        return;
    }
    else {
        state_min[state][root] = dis;
    }
    if (depth<=n) {
        for (int i=n; i>=1; --i) {
            if (!(state & (1<<(i-1)))) {
                state |= 1<<(i-1);
                float d = dist(cheeses[i], cheeses[root]);
                dis += d;
                dfs(depth+1, i);
                dis -= d;
                state &= ~(1<<(i-1));
            }
        }
    }
}
int main() {
    memset(state_min, 0x7f, sizeof(state_min));
    scanf("%d", &n);
    for (int i=1; i<=n; ++i) {
        scanf("%f%f", &cheeses[i].x, &cheeses[i].y);
    }
    dfs(1, 0);
    float result=1e30;
    for (int i=1; i<=n; ++i) {
        if (state_min[(1<<n)-1][i]< result) result = state_min[(1<<n)-1][i];
    }
    printf("%.2f", result);
    return 0;
}

