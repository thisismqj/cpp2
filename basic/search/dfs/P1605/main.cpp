#include <bits/stdc++.h>
using namespace std;
char maze[6][6];
int n, m, t;
int sx, sy, fx, fy;
int result=0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
void dfs(int x, int y) {
    if (maze[x][y] == 'x'||maze[x][y] == 'p') return;
    if (maze[x][y] == 'f') {
        ++result;
        return;
    }
    maze[x][y] = 'p';
    for (int i=0; i<4; ++i) {
        dfs(x+dx[i], y+dy[i]);
    }
    maze[x][y] = 0;
}

int main() {
    scanf("%d%d%d", &n, &m, &t);
    scanf("%d%d%d%d", &sx, &sy, &fx, &fy);
    for (int i=0; i<=m+1; ++i) {
        maze[0][i] = 'x';
        maze[n+1][i] = 'x';
    }
    for (int i=1; i<=n;++i) {
        maze[i][0] = 'x';
        maze[i][m+1] = 'x';
    }
    maze[sx][sy] = 's';
    maze[fx][fy] = 'f';
    for (int i=1; i<=t; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        maze[x][y] = 'x';
    }
    dfs(sx, sy);
    printf("%d", result);
    return 0;
}

