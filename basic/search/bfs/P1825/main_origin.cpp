#include <bits/stdc++.h>
using namespace std;
char field[305][305];
bool checked[305][305];
int n, m;
int ex, ey;// exit
int cx, cy;
struct Pos {int x, y, depth;};
queue<Pos> Q;
int top = 0;
int dx[4]={1, 0, -1 ,0};
int dy[4]={0, 1, 0, -1};
Pos portal[26][2];
void print() {
    putchar('\n');
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j) {
            putchar(checked[i][j]?'x':'.');
        }
        putchar('\n');
    }
}
int main() {
    scanf("%d%d", &n, &m);
    getchar();
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j) {
            field[i][j] = getchar();
            if (field[i][j] == '=') {
                ex = i;ey = j;
            }
            if (field[i][j] == '@') {
                cx = i;cy = j;
            }
            if ('A' <= field[i][j] && field[i][j] <= 'Z') {
                if (portal[field[i][j]-'A'][0].x==0)
                    portal[field[i][j]-'A'][0]={i, j};
                else portal[field[i][j]-'A'][1]={i, j};
            }
        }
        getchar();
    }
    Q.push({cx, cy, 0});
    while (!Q.empty()) {
        Pos a = Q.front();
        Q.pop();
        checked[a.x][a.y] = true;
        // print();
        for (int i=0; i<4; ++i) {
            int x = a.x+dx[i], y = a.y+dy[i];
            if (!checked[x][y] && field[x][y]!='#') {
                if (field[x][y] == '=') {
                    printf("%d", a.depth+1);
                    return 0;
                } else if (field[x][y] == '.') {
                    Q.push({x, y, a.depth+1});
                } else {
                    int p_i = field[x][y] - 'A';
                    if (portal[p_i][0].x==x&&portal[p_i][0].y==y) {
                        Q.push(Pos{portal[p_i][1].x, portal[p_i][1].y, -(a.depth+1)});
                    } else {
                        Q.push(Pos{portal[p_i][0].x, portal[p_i][0].y, -(a.depth+1)});
                    }
                }
            }
        }
    }
    return 0;
}

