#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10];
int k;
char n[35];
int poss[10];// i 可能变成的数的个数(自身包括)
__int128 ans=1;
void bfs(int x) {
    int ans=0;
    // bfs找x可达点(自身)个数
    bool vis[10];
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(x);
    vis[x]=true;
    while (!Q.empty()) {
        // 将未vis的入队
        // ans自增
        int h = Q.front(); Q.pop();
        ++ans;
        for (int d: adj[h]) {
            if (!vis[d]) vis[d]=true, Q.push(d);
        }
    }
    poss[x] = ans;
}
inline void print(__int128 n){
    if(n<0){
        putchar('-');
        n*=-1;
    }
    if(n>9) print(n/10);
    putchar(n % 10 + '0');
}
int main() {
    scanf("%s%d", n, &k);
    int len = strlen(n);
    for (int i=1; i<=k; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        adj[x].push_back(y);
    }
    for (int i=0; i<10; ++i) bfs(i);
    for (int i=0; i<len; ++i) {
        ans*=poss[n[i]-'0'];
    }
    print(ans);
}
