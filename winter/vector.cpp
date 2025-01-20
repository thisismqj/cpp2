#include <bits/stdc++.h>
using namespace std;
int n, m;
struct Vec{
    int f[11];
    int id;
    bool operator<(Vec &b) {
        for (int i=1; i<=m; ++i) {
            if (f[i]>=b.f[i]) return false;
        }
        return true;
    }
} vecs[1005];
bool chk(Vec& v1, Vec&v2) {
    for (int i=1; i<=m; ++i) {
        if (v1.f[i]>=v2.f[i]) return false;
    }
    return true;
}
int ans[1005];
int main() {
    cin>>n>>m;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j) {
            cin>>vecs[i].f[j];
            vecs[i].id = i;
        }
    sort(vecs+1, vecs+1+n);
    for (int i=1; i<=n-1; ++i) {
        int j=1;
        while (!chk(vecs[i], vecs[i+j])&&i+j<=n) ++j;
        if (i+j<=n)
            ans[vecs[i].id] = vecs[i+j].id;
    }
    for (int i=1; i<=n; ++i) {
        cout<<ans[i]<<endl;
    }
    return 0;
}
