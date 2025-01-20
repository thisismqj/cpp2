#include <bits/stdc++.h>
using namespace std;
// 无色块可到达的条件:
//   周围存在可到达的非无色块k
//   费用: k费min + 2
// 有色块到达条件:
//   周围存在可到达的块
//   费用:
//   min (k费(同色)/ k费+1(异色))
int m, n;
int b[105][105];
bool vis[105][105];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int c_m = INT_MAX;
int c=0;
void dfs(int x, int y, bool mod) {
    //cout<<x<<" "<<y<<endl;
    vis[x][y] = 1;
    if (x==m&&y==m) {
        //cout<<c<<endl;
        c_m = min(c_m, c);
        vis[x][y] = 0;
    } else {
        for (int i=0; i<4; ++i) {
            int dst_x = x+dx[i], dst_y = y+dy[i];
            if (dst_x<=0||dst_y<=0||dst_x>m||dst_y>m||vis[dst_x][dst_y]) continue;
            if (b[dst_x][dst_y]!=-1) {
                int dc = b[dst_x][dst_y]!=b[x][y];
                c += dc;
                dfs(dst_x, dst_y, false);
                c-=dc;
            } else {
                if (mod) continue;
                c+=2;
                b[dst_x][dst_y] = b[x][y];
                dfs(dst_x, dst_y, true);
                b[dst_x][dst_y] = -1;
                c-=2;
            }
        }
        vis[x][y] = 0;
    }
}
int main() {
    cin>>m>>n;
    memset(b, -1, sizeof(b));
    for (int i=1; i<=n; ++i) {
        int x, y, c;
        cin>>x>>y>>c;
        b[x][y] = c;
    }
    dfs(1, 1, false);
    if (c_m == INT_MAX) cout<<-1;
    else cout<<c_m;
    return 0;
}
