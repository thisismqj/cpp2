#include <bits/stdc++.h>
using namespace std;
vector<int> edges[10005];
int deg[10005];
char color[10005]; // 0: 灰色 g: 绿色 r: 红色
bool checked[10005];
int r, g;
int ans=0;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i=1; i<=m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        edges[x].push_back(y);
        edges[y].push_back(x);
        ++deg[x];++deg[y];
    }
    queue<int> Q;
    for (int i=1; i<=n; ++i) {
        if (!checked[i]) {
            r=g=0;
            Q.push(i);
            color[i] = 'r';++r;
            while (!Q.empty()) {
                int x=Q.front(); Q.pop();
                checked[x] = true;
                for (int d:edges[x]) {
                    if (deg[d]!=0) {
                        --deg[d];--deg[x]; // 减边
                        if (deg[d]!=0) Q.push(d);
                        if (!color[d]) {
                            color[d] = (color[x]=='g')?'r':'g';
                            if (color[d]=='g') ++g;else ++r;
                        }
                        else if (color[d]==color[x]) {
                            printf("Impossible");
                            return 0;
                        }
                    }
                }
            }
            ans+=min(r, g);
        }
    }
    printf("%d", ans);
    return 0;
}
