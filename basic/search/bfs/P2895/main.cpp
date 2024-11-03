#include <bits/stdc++.h>
using namespace std;
int m;
int farm[305][305];
int timer[305][305];
queue<pair<int, int>> Q;
int main() {
    memset(farm, -1, sizeof(farm));
    memset(timer, -1, sizeof(timer));
    scanf("%d", &m);
    for (int i=1; i<=m; ++i) {
        int x, y, t;
        scanf("%d%d%d", &x, &y, &t);
        if (farm[x][y] == -1 || farm[x][y] > t)
            farm[x][y] = t;
        if (x-1>=0&&(farm[x-1][y] == -1||farm[x-1][y]>t))
            farm[x-1][y] = t;
        if (farm[x+1][y] == -1||farm[x+1][y]>t)
            farm[x+1][y] = t;
        if (y-1>=0&&(farm[x][y-1] == -1||farm[x][y-1]>t))
            farm[x][y-1] = t;
        if (farm[x][y+1] == -1||farm[x][y+1]>t)
            farm[x][y+1] = t;
    }
    timer[0][0] = 0;
    Q.push({0, 0});
    while (!Q.empty()) {
        int pos[2];
        pos[0] = Q.front().first;
        pos[1] = Q.front().second;
        Q.pop();
        if (farm[pos[0]][pos[1]] == -1) {
            printf("%d", timer[pos[0]][pos[1]]);
            return 0;
        } else if (farm[pos[0]][pos[1]] > timer[pos[0]][pos[1]]) {
            int x = pos[0]-1, y=pos[1];
            if (x>=0 && timer[x][y]==-1) {
                timer[x][y] = timer[pos[0]][pos[1]] + 1;
                Q.push({x, y});
            }
            x = pos[0]+1, y=pos[1];
            if (timer[x][y]==-1) {
                timer[x][y] = timer[pos[0]][pos[1]] + 1;
                Q.push({x, y});
            }
            x = pos[0], y=pos[1]-1;
            if (y>=0 && timer[x][y]==-1) {
                timer[x][y] = timer[pos[0]][pos[1]] + 1;
                Q.push({x, y});
            }
            x = pos[0], y=pos[1]+1;
            if (timer[x][y]==-1) {
                timer[x][y] = timer[pos[0]][pos[1]] + 1;
                Q.push({x, y});
            }
        }
    }
    printf("-1");
    return 0;
}

