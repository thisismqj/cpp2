#include <bits/stdc++.h>
using namespace std;
int n;
struct Node {
    int left, right, root;
} t[105]; // val即索引
int p=1;
void add(int rt, int val) {
// 给根节点添加子树
    if (t[rt].left) {
// 右
        t[rt].right = val;
        t[val].root = rt;
    } else {
        t[rt].left = val;
        t[val].root = rt;
    }
}
int dfs(int rt) {
// 返回树的最大深度
    if (rt==0) return 0;
    return 1+max(dfs(t[rt].left), dfs(t[rt].right));
}
int wid[105]; // 深度桶
void wdfs(int rt, int depth=1) {
    // 从rt开始遍历中左右
    // 如果rt存在
    if (rt) {
        wid[depth]++;
        wdfs(t[rt].left, depth+1);
        wdfs(t[rt].right, depth+1);
    }
}
bool vis[105];
queue<pair<int, int>> Q; // dst, val
int bfs(int x, int y) {
    vis[0] = true;
    // src, dst
    Q.push({0, x});
    while (!Q.empty()) {
        int dst = Q.front().first;
        int val = Q.front().second;
        Q.pop();
        if (val==y) return dst;
        vis[val] = true;
        if (!vis[t[val].left]) {
            Q.push({dst+1, t[val].left});
        }
        if (!vis[t[val].right]) {
            Q.push({dst+1, t[val].right});
        }
        if (!vis[t[val].root]) {
            Q.push({dst+2, t[val].root});
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i=1; i<=n-1; ++i) {
        int r,v;
        scanf("%d%d", &r, &v);
        add(r, v);
    }
    int x, y;
    scanf("%d%d", &x, &y);
    int dep = dfs(1);
    wdfs(1);
    int w = 0;
    for (int i=1; i<=dep; ++i) {
        if (wid[i]>w) w = wid[i];
    }
    int dst = bfs(x, y);
    printf("%d\n%d\n%d", dep, w, dst);
    return 0;
}
