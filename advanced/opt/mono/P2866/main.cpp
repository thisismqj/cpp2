#include <bits/stdc++.h>
using namespace std;
int n;
int st[80005];
int _p = 0;// size
int main() {
    unsigned long long ans=0;
    scanf("%d", &n);
    // get a number x
    // check stack, pop until top > x
    // add stack size to ans
    // push x
    for (int i=1; i<=n; ++i) {
        int x;
        scanf("%d", &x);
        while (_p>0&&st[_p-1]<=x) {
            --_p;
        }
        ans += _p;
        st[_p++] = x;
    }
    printf("%llu", ans);
    return 0;
}
