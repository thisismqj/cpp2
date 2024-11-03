#include <bits/stdc++.h>
using namespace std;
bool color[20005]; // 1：染色
struct Edge {
    int n1, n2;
    int c;
    bool operator<(Edge& e2) {
        return c<e2.c;
    }
} edges[100005];
int n, m;
int max_ei() {
    for (int i=m; i>=1; --i) {
        if (color[edges[i].n1]==color[edges[i].n2])
            return i;
    }
    return 0;
}
int dfs(int mei) { // 返回c
    // 求染节点1,2的最大值
    int maxi0 = max_ei();
    int max0 = edges[maxi0].c;
    color[edges[mei].n1]=(color[edges[mei].n1]==0);
    int maxi1 = max_ei();
    int max1 = edges[maxi1].c;
    color[edges[mei].n1]=(color[edges[mei].n1]==0);

    color[edges[mei].n2]=(color[edges[mei].n2]==0);
    int maxi2 = max_ei();
    int max2 = edges[maxi2].c;
    color[edges[mei].n2]=(color[edges[mei].n2]==0);
    // 已最优
    if (max0<=max1 && max0<=max2) return max0;
    if (max1>max2) {
        // 2染色的分支
        color[edges[mei].n2]=(color[edges[mei].n2]==0);
        return dfs(maxi2);
        color[edges[mei].n2]=(color[edges[mei].n2]==0);
    } else if (max1<max2) {
        // 1染色
        color[edges[mei].n1]=(color[edges[mei].n1]==0);
        return dfs(maxi1);
        color[edges[mei].n1]=(color[edges[mei].n1]==0);
    } else {
        // 双分支
        color[edges[mei].n1]=(color[edges[mei].n1]==0);
        int c1 = dfs(maxi1);
        color[edges[mei].n1]=(color[edges[mei].n1]==0);
        color[edges[mei].n2]=(color[edges[mei].n2]==0);
        int c2 = dfs(maxi2);
        color[edges[mei].n2]=(color[edges[mei].n2]==0);
        return min(c1, c2);
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i=1; i<=m; ++i) {
        scanf("%d%d%d", &edges[i].n1, &edges[i].n2, &edges[i].c);
    }
    sort(edges+1, edges+m+1);
    int minc = dfs(m);
    printf("%d", minc);
    return 0;
}
