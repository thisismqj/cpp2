#include <bits/stdc++.h>
using namespace std;
double dist[405];
struct Edge {
    int nxt;
    double dist;
};
vector<Edge> adj[405];
struct Pos{int x, y;} city_pos[105][5];
void connect(int n1, int n2, double dist) {
    adj[n1].push_back({n2, dist});
    adj[n2].push_back({n1, dist});
}
struct cmp {
    bool operator()(int a, int b) {return dist[a]>dist[b];}
};
double dijkstra(int c1, int c2) {
    double minc = INT_MAX;
    for (int i=1; i<=4; ++i) {
        memset(dist, 0x42, sizeof(dist));
        dist[4*c1-4+i] = 0.;
        priority_queue<int, vector<int>, cmp> Q;
        Q.push(4*c1-4+i);
        while (!Q.empty()) {
            int x=Q.top();
            Q.pop();
            for (Edge& e:adj[x]) {
                if (dist[e.nxt]>e.dist+dist[x]) {
                    dist[e.nxt] = e.dist+dist[x];
                    Q.push(e.nxt);
                }
            }
        }
        for (int j=1; j<=4; ++j) {
            minc = min(minc, dist[4*c2-4+j]);
        }
    }
    return minc;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int _i=1; _i<=n; ++_i) {
        int s, t, a, b;
        scanf("%d%d%d%d", &s, &t, &a, &b);
        for (int i=1; i<=400; ++i) adj[i].clear();
        memset(city_pos, 0, sizeof(city_pos));
        for (int i=1; i<=s; ++i) {
            int x1, y1, x2, y2, x3, y3, T, x4, y4;
            scanf("%d%d%d%d%d%d%d", &x1,&y1,&x2,&y2,&x3,&y3,&T);
            int v1x, v1y, v2x, v2y, v3x, v3y;
            v1x=x2-x1;v2x=x3-x2;v3x=x1-x3;
            v1y=y2-y1;v2y=y3-y2;v3y=y1-y3;
            if (v1x*v3x+v1y*v3y==0) {
                // 1->4
                x4=x1+v1x-v3x;
                y4=y1+v1y-v3y;
            } else if (v1x*v2x+v1y*v2y==0) {
                // 2->4
                x4=x2+v2x-v1x;
                y4=y2+v2y-v1y;
            } else {
                // 3->4
                x4=x3+v3x-v2x;
                y4=y3+v3y-v2y;
            }
            city_pos[i][1] = {x1, y1};
            city_pos[i][2] = {x2, y2};
            city_pos[i][3] = {x3, y3};
            city_pos[i][4] = {x4, y4};
            connect(4*i-3, 4*i-2,
                    T*sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
            connect(4*i-3, 4*i-1,
                    T*sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1)));
            connect(4*i-3, 4*i,
                    T*sqrt((x4-x1)*(x4-x1)+(y4-y1)*(y4-y1)));
            connect(4*i-2, 4*i-1,
                    T*sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2)));
            connect(4*i-2, 4*i,
                    T*sqrt((x4-x2)*(x4-x2)+(y4-y2)*(y4-y2)));
            connect(4*i-1, 4*i,
                    T*sqrt((x4-x3)*(x4-x3)+(y4-y3)*(y4-y3)));
        }
        for (int i=1; i<=s-1; ++i) {
            for (int j=i+1; j<=s; ++j) {
                for (int k=1; k<=4; ++k) {
                    for (int l=1; l<=4; ++l) {
                        connect(4*i-4+k, 4*j-4+l,
    t*sqrt((city_pos[i][k].x-city_pos[j][l].x)*
           (city_pos[i][k].x-city_pos[j][l].x)+
           (city_pos[i][k].y-city_pos[j][l].y)*
           (city_pos[i][k].y-city_pos[j][l].y)));
                    }
                }
            }
        }
        printf("%.1lf", dijkstra(a, b));
    }
}
