#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> edges[1505]; // dst, wei
vector<pair<int, int>> src[1505]; // src, wei
int mx[1505];
int ind[1505];
void bfs() {
    queue<int> Q;
    Q.push(1);
    while (!Q.empty()) {
        // 更新从1到该节点的最长路径
        int x=Q.front(); Q.pop();
        for (auto e:src[x]) {
            if (mx[e.first]+e.second>mx[x]) {
                // 选出最大(从1到该节点的路径)的一条入边
                mx[x] = mx[e.first]+e.second;
            }
        }
        for (auto e:edges[x]) {
            --ind[e.first];
            if (ind[e.first]==0) {
                Q.push(e.first);
            }
        }
    }
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    memset(mx, 0x80, sizeof(mx));
    mx[1]=0;
    for (int i=1; i<=m; ++i) {
        int s, d, w;
        scanf("%d%d%d", &s, &d, &w);
        edges[s].push_back({d, w});
        src[d].push_back({s, w});
    }
    queue<int> dQ;
    for (int i=2; i<=n; ++i) {
        ind[i] = src[i].size();
        if (ind[i]==0) dQ.push(i);
    }
    // 将其他入度0的节点置0
    while (!dQ.empty()) {
        int x = dQ.front(); dQ.pop();
        for (auto e:edges[x]) {
            if (--ind[e.first]==0) {
                dQ.push(e.first);
            }
        }
    }
    bfs();
    if (mx[n]>(int)0x80808080)
        printf("%d", mx[n]);
    else printf("-1");
    return 0;
}
