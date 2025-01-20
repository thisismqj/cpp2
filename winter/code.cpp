#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[25], b[25];
int main() {
    cin>>n>>m;
    for (int i=1; i<=n; ++i) cin>>a[i];
    for (int i=1; i<=n; ++i) {
        b[i] = m%a[i];
        m/=a[i];
    }
    for (int i=1; i<=n; ++i) cout<<b[i]<<' ';
    return 0;
}

