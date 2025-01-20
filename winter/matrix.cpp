#include <bits/stdc++.h>
using namespace std;
int n, x, y, a, b, c;
int main() {
    cin>>n;
    cin>>x>>y;
    cin>>a>>b>>c;
    for (int i=3; i<=n; ++i) {
        int t = (a*y+b*x+c)%998244353;
        x=y; y=t;
    }
    cout<<y;
    return 0;
}
