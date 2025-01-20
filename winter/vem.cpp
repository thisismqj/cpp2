#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int f[5005], g[5005];
bool cmp(int a, int b) {return a>b;}
int main() {
    cin>>n>>m>>k;
    for (int i=1; i<=n; ++i)
        g[i] = i*m;
    for (int i=1; i<=k; ++i)
        cin>>f[i];
    sort(f+1, f+1+k, cmp);
    bool t = true;
    for (int i=1; i<=n; ++i) {
        t = ( f+1+k-lower_bound(f+1, f+1+k, i) )<=g[i];
        if (!t) break;
    }
    if (!t) cout<<"No";
    else cout<<"Yes";
    return 0;
}
