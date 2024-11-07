#include <bits/stdc++.h>
#define f(x) f[(x)%(t+1)]
using namespace std;
int l, s, t, m;
int f[25];
set<int> stone;
int main() {
    memset(f, -1, sizeof(f));
    cin>>l>>s>>t>>m;
    for (int i=1; i<=m; ++i) {
        int x;
        cin>>x;
        stone.insert(x);
    }
    f[0] = 0; // init
    for (int i=s; i<t; ++i) {
        if (stone.find(i)!=stone.end()) {
            f[i]=1;
        } else {
            f[i]=0;
        }
    }
    for (int i=t; i<=l+t-1; ++i) {
        bool has_stone=false;
        if (stone.find(i)!=stone.end()) {
            has_stone=true;
        }
        for (int j=i-t; j<=i-s; ++j) {
            if (f(j)!=-1) {
                if (f(i)==-1)
                    f(i) = f(j)+has_stone;
                else f(i) = min(f(i), f(j)+has_stone);
            }
        }
        printf("Stone of %d:%d\n", i, f(i));
    }
    int ans=INT_MAX;
    for (int i=l; i<=l+t-1; ++i) {
        if (f(i)!=-1)
            ans=min(ans, f(i));
    }
    printf("%d", ans);
}
