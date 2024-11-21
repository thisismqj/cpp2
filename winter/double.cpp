#include <bits/stdc++.h>
using namespace std;
unsigned x;
int main() {
    cin>>x;
    x<<1;
    int cnt=1;
    while (x!=1) {
        x>>=1;
        ++cnt;
    }
    cout<<cnt;
    return 0;
}
