#include <bits/stdc++.h>
using namespace std;
bool vis[200005];
int vi[200005];
int n;
int to[200005];
struct My2Q {
    static const int n=2;
    struct Pair {int first, second;} p[n];
    void push(int first, int second) {
        p[_p] = {first, second};
        _p++;
        _p%=n;
    }
    void pop() {
        _p+=n-1;
        _p%=n;
    }
    Pair front() {
        return p[(_p+n-1)%n];
    }
    int _p=0;
};
int fread() {
    int x=0;
    char ch;
    while ((ch=getchar())!=' '&&ch!='\n') {
        x=10*x+(ch-'0');
    }
    return x;
}
int bfs(int n) {
    memset(vi, 0, sizeof(vi));
    My2Q Q; // depth, val
    Q.push(1, n);
    while (true) {
        int x = Q.front().second, d=Q.front().first; Q.pop();
        vis[x] = true;
        if (vi[x]) return d-vi[x];
        else
            vi[x] = d;
        Q.push(d+1, to[x]);
    }
}
int main() {
    n=fread();
    for (int i=1; i<=n; ++i) {
        int y=fread();
        to[i] = y;
    }
    int r = INT_MAX;
    for (int i=1; i<=n; ++i) {
        if (!vis[i]) {
            r = min(r, bfs(i));
        }
    }
    printf("%d", r);
    return 0;
}
