#include <bits/stdc++.h>
using namespace std;
int n, m;
int ponds=0;
char land[105][105];
int dx[8] = {-1,-1,-1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0,-1,-1};
void dfs(int x, int y) {
    // 从标记(x, y)开始搜索
    // 搜索到则标记U, 递归进行
    for (int i=0; i<8; ++i) {
        char ch = land[x+dx[i]][y+dy[i]];
        if (ch=='W') {
        land[x+dx[i]][y+dy[i]] = 'U';
            dfs(x+dx[i],y+dy[i]);
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    getchar();
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j) {
            land[i][j] = getchar();
        }
        getchar();
    }
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j) {
            if (land[i][j]=='W') {
                ++ponds;
                land[i][j] = 'U';
                dfs(i, j);
            }
        }
    }

    printf("%d", ponds);
    return 0;
}

