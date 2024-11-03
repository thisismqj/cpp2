#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
struct Pos {
    int x, y;
};
const Pos operator+(const Pos &p1, const Pos &p2) {
    return Pos{p1.x+p2.x, p1.y+p2.y};
}
Pos horse_step[8] = 
{{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, 
{1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
queue<Pos> Q;           // 保存路径
int board[405][405];    // 记录答案
int main() {
    scanf("%d%d%d%d", &n, &m, &x, &y);
    memset(board, -1, sizeof(board));
    Q.push(Pos{x, y});
    board[x][y] = 0;
    // bfs:
    // 遍历可达点(1. 没踩过 2. 未出界), 
    // 存入队尾, 直到队列空空
    // 每次从队首取出一个位置, 增加深度(步数)
    while (!Q.empty()) {
        Pos s = Q.front();
        Q.pop();
        int src_step = board[s.x][s.y];
        for (int i=0; i<8; ++i) {
            Pos d = s + horse_step[i];
            if (d.x>=1&&d.y>=1&&d.x<=n&&d.y<=m) {
                int &dst_step = board[d.x][d.y];
                if (dst_step == -1) {
                    dst_step = src_step + 1;
                    Q.push(d);
                }
            }
        }
    }
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j) {
            printf("%d ",board[i][j]);
        }
        putchar('\n');
    }
    return 0;
}

