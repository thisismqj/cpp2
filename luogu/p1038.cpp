#include <bits/stdc++.h>
using namespace std;
int n, p;
const int MAX_NODE = 2005;
int ind[MAX_NODE], output[MAX_NODE], _op=0;
struct Node {int st, u;} nodes[MAX_NODE];
struct Edge {int dest, w;};
vector<Edge> adj[MAX_NODE];
// 输入:
//      更新入度, 出度
//
// 输出神经元是出度0的节点
// 拓扑排序(需注意状态为>0), 更新权值, 将出度为0的标号记录
// 标号排序，输出(正状态)
int main() {
    scanf("%d%d", &n, &p);
    queue<int> Q;
    for (int i=1; i<=n; ++i) {
        scanf("%d%d", &nodes[i].st, &nodes[i].u);
        if (nodes[i].st>0) Q.push(i);
    }
    for (int i=1; i<=p; ++i) {
        int src, dst, w;
        scanf("%d%d%d", &src, &dst, &w);
        adj[src].push_back({dst, w});
        ++ind[dst];
    }
    while (!Q.empty()) {
        // Q中状态非0, 将遍历
        // 更新目标状态
        // 加入序列(状态>0且入度0)
        // 若目标为空则加入输出序列
        bool has_output = false;
        int x = Q.front(); Q.pop();
        for (Edge &e: adj[x]) {
            has_output = true;
            --ind[e.dest];
            if (nodes[x].st>0) nodes[e.dest].st += e.w*nodes[x].st;
            if (ind[e.dest]==0) {
                nodes[e.dest].st-=nodes[e.dest].u;
                Q.push(e.dest);
            }
        }
        if (!has_output&&nodes[x].st>0) {
            output[_op++] = x;
        }
    }
    // 排序
    sort(output, output+_op);
    for (int i=0; i<_op; ++i) {
        printf("%d %d\n", output[i], nodes[output[i]].st);
    }
    if (_op==0) printf("NULL\n");
}
