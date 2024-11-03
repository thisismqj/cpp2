#include <bits/stdc++.h>
using namespace std;
char arr[1505][1505];
bool vis[1505][1505], bvis[260];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
short father[1505][1505];
int _fp = 1;
int st[65500];
int _sp=0;
int n, m;
vector<int> edges[260];
void printfa() {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            printf("%d", father[i][j]);
        }
        putchar('\n');
    }
}
void dfsb(int x, int y, int f) {
    // 置vis, 置f, 并将与(x, y)连通的递归
    vis[x][y] = true;
    father[x][y] = f;
    for (int i=0; i<4; ++i) {
        int dstx = x+dx[i], dsty = y+dy[i];
        if (dstx>=0&&dstx<=n-1&&dsty>=0&&dsty<=m-1&&
        arr[dstx][dsty]!='#'&&!vis[dstx][dsty]) {
            dfsb(dstx, dsty, f);
        }
    }
}
bool chk(int i) {
    // 在栈(st下2位)中查找，若有i返回true
    for (int i=0; i<=_sp-2; ++i) {
        if (st[i]==i) return true;
    }
    return false;
}
bool dfs(int n, int las) {
    // 对图dfs, 每次将路径入栈，检查下一步dfs是否chk, 是则返回true
    if (chk(n)) return true;
    st[_sp++] = n;
    for (int e:edges[n]) {
        if (e==n) return true;// 自环
        if (e!=las)
            if (dfs(e, n)) return true;
    }
    --_sp;
    return false;
}
int main() {
    while (true) {
        n=0;
        scanf("%d%d\n", &n, &m);
        if (n==0) break;
        memset(vis, 0, sizeof(vis));
        memset(bvis, 0, sizeof(bvis));
        int sx, sy;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                arr[i][j] = getchar();
                if (arr[i][j]=='S') {sx=i, sy=j;}
            }
            getchar();
        }
        // 建集 
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (arr[i][j]!='#'&&!vis[i][j]) dfsb(i, j, _fp++);
            }
        }
        // 建图
        for (int i=0; i<n; ++i) {
            if (arr[i][0]!='#'&&arr[i][m-1]!='#') {
                int x = father[i][0], y=father[i][m-1];
                bool exist = false;
                for (int e:edges[x]) {
                    if (e==y) exist = true;
                }
                if (!exist) {
                    edges[x].push_back(y);
                    edges[y].push_back(x);
                }
            }
        }
        for (int i=0; i<m; ++i) {
            if (arr[0][i]!='#'&&arr[n-1][i]!='#') {
                int x = father[0][i], y=father[n-1][i];
                bool exist = false;
                for (int e:edges[x]) {
                    if (e==y) exist = true;
                }
                if (!exist) {
                    edges[x].push_back(y);
                    edges[y].push_back(x);
                }
            }
        }
        // 查环
        if (dfs(father[sx][sy], father[sx][sy])) {
            printf("Yes\n");
        } else printf("No\n");
    }
    return 0;
}
