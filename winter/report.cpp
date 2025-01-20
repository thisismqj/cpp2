#include <bits/stdc++.h>
using namespace std;
int h[20005];
int b, n;
int main() {
    cin>>n>>b;
    for (int i=1; i<=n; ++i)
        cin>>h[i];
    sort(h+1, h+1+n);
    int cnt=0;
    for (int i=n; i>=1; --i) {
        b-=h[i];
        ++cnt;
        if (b<0) break;
    }
    cout<<cnt;
    return 0;
}
