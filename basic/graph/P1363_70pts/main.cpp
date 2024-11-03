#include <bits/stdc++.h>
using namespace std;
char arr[1505][1505];
bool vis[1505][1505];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
unsigned short father[1505][1505];
int _fp = 1;
int st[65500];
int _sp=0;
int n, m;
struct Edge {
    short dst;
    char dx, dy;
};
vector<Edge> edges[65500];
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
int chk(int n) {
    // 在栈(st下2位)中查找，若有i返回i
    for (int i=0; i<=_sp-2; ++i) {
        if (st[i]==n) return i;
    }
    return -1;
}
bool dfs(int n) {
    // 对图dfs, 将节点入栈
    // 如果chk, 边积分，不为0则成功
    // 周围节点在非墙且不为栈顶下2时dfs
    st[_sp++] = n;
    int l = chk(n);
    if (l!=-1) {
        int dx=0, dy=0;
        for (int i=l; i<_sp-1; ++i) {
            int d=st[i+1];
            for (Edge &e: edges[st[i]]) {
                if (e.dst==d) {
                    dx+=e.dx;
                    dy+=e.dy;
                    break;
                }
            }
        }
        if (dx!=0||dy!=0) return true;
        else {--_sp;return false;};
    }
    for (Edge &e: edges[n]) {
        if (e.dst!=st[_sp-1-1]) {
            if (dfs(e.dst)) return true;
        }
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
        int sx, sy;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                cin>>arr[i][j];
                if (arr[i][j]=='S') {sx=i, sy=j;}
            }
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
                for (Edge& e:edges[x]) {
                    if (e.dst==y) exist = true;
                }
                if (!exist) {
                    edges[x].push_back({y, 0, -1});
                    edges[y].push_back({x, 0, 1});
                }
            }
        }
        for (int i=0; i<m; ++i) {
            if (arr[0][i]!='#'&&arr[n-1][i]!='#') {
                int x = father[0][i], y=father[n-1][i];
                bool exist = false;
                for (Edge& e:edges[x]) {
                    if (e.dst==y) exist = true;
                }
                if (!exist) {
                    edges[x].push_back({y, -1, 0});
                    edges[y].push_back({x, 1, 0});
                }
            }
        }
        // 查环
        if (dfs(father[sx][sy])) {
            printf("Yes\n");
        } else printf("No\n");
    }
    return 0;
}
