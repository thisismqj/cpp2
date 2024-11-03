#include <bits/stdc++.h>
using namespace std;
inline char c2n(char c) {
    return c-'A';
}
int n;
vector<char> edges[30]; 
int ind[30];
char st[30];
int _sp=0;
bool vis[30];
bool dfs(char c);
int main() {
    int m;
    scanf("%d%d\n", &n, &m);
    for (int i=1; i<=m; ++i) {
        char x, y;
        scanf("%c<%c\n", &x, &y);
        x = c2n(x); y = c2n(y);
        edges[x].push_back(y);
        ++ind[y];
        // 遍历入度0的点入队
        int zcnt=0;
        queue<char> Q;
        for (int i=0; i<n; ++i) {
            if (ind[i]==0) {Q.push(i); ++zcnt;}
        }
        char z = Q.front();
        // 拓排
        bool vis[30];
        memset(vis, 0, sizeof(vis));
        int iind[30];
        memcpy(iind, ind, sizeof(ind));
        while (!Q.empty()) {
            char x=Q.front();Q.pop();
            vis[x] = true;
            for (char e:edges[x]) {
                --iind[e];
                if (iind[e]==0) Q.push(e);
            }
        }
        int j=0;
        for (int i=0; i<n; ++i) j+=!vis[i];
        if (j!=0) {
            printf("Inconsistency found after %d relations.", i);
            return 0;
        }
        if (zcnt==1) {
            // 从z开始dfs, 直到找到一条路径使得全vis.（或不存在）
            // 到达终点： 出度为0, 若非全vis return false;否则return true;
            // 将路径入栈。
            if (dfs(z)) {
                printf("Sorted sequence determined after %d relations: ", i);
                // 输出st
                for (int i=0; i<_sp; ++i) putchar(st[i]);
                putchar('.');
                return 0;
            }
        }
    }
    printf("Sorted sequence cannot be determined.");
    return 0;
}
bool dfs(char c) {
    st[_sp++] = c+'A';
    vis[c] = true;
    bool end = true;
    for (char e: edges[c]) {
        end = false;
        if (dfs(e)) return true;
    }
    if (end) {
        int j=0;
        for (int i=0; i<n; ++i) {
            j+=!vis[i];
        }
        if (j==0) 
            return true;
    }
    vis[c] = false;
    --_sp;
    return false;
}
