#include <bits/stdc++.h>
using namespace std;
// dp
// f[x1][y1][x2][y2]表示第一次走(x1, y1), 第二次走(x2, y2)
int arr[12][12];
int f[12][12][12][12];
int n;
int dfs(int x1, int y1, int x2, int y2) {
    if (f[x1][y1][x2][y2]!=-1) return f[x1][y1][x2][y2];
    if (x1>n||x2>n||y1>n||y2>n) return 0;
    int ans = arr[x1][y1] + (!((x1==x2)&&(y1==y2)))*arr[x2][y2] +
    max(max(dfs(x1+1, y1, x2+1, y2),dfs(x1+1, y1, x2, y2+1)),
    max(dfs(x1, y1+1, x2+1, y2), dfs(x1, y1+1, x2, y2+1)));
    return f[x1][y1][x2][y2] = ans;
}
int main() {
    memset(f, -1, sizeof(f));
    cin>>n;
    for (;;) {
        int x, y, c;
        cin>>x>>y>>c;
        if (x==0&&y==0&&c==0) break;
        arr[x][y] = c;
    }
    cout<<dfs(1, 1, 1, 1);
    return 0;
}
