#include <bits/stdc++.h>
using namespace std;
int n, k, bucket[300005];
int main() {
    cin>>n>>k;
    for (int i=1; i<=n; ++i) {
        int x;
        cin>>x;
        ++bucket[x];
    }
    int cnt=0;
    for (int i=1; i<=300000; ++i) {
        if (bucket[i]) {
            ++cnt;
            if (cnt==k) {
                cout<<i;
                return 0;
            }
        }
    }
    return 0;
}
