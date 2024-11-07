#include <bits/stdc++.h>
using namespace std;
int f[10005];
int s, t, m, l;
set<int> stones;
int sto[105], _sp=1;
int main() {
    memset(f, 0x7f, sizeof(f));
    cin>>l>>s>>t>>m;
    if (s==t) {
        int x, ans=0;
        for (int i=1; i<=m; ++i) {
            cin>>x;
            if (x%s==0) ++ans;
        }
        cout<<ans;
    } else {
        int x;
        for (int i=1; i<=m; ++i) {
            cin>>x;
            sto[_sp++] = x;
        }
        sort(sto+1, sto+1+m);
        l=min(sto[m]+90, l);
        int last_stone = 0, last_shortened_stone=0;
        for (int i=1; i<=m; ++i) {
            int x=sto[i];
            if (x-last_stone>90) {
                l-=x-last_stone-90;
                //printf("Stone%d: %d\n", i, last_shortened_stone+90);
                stones.insert(last_shortened_stone+90);
                last_shortened_stone+=90;
            } else {
                //printf("Stone%d: %d\n", i, last_shortened_stone+x-last_stone);
                stones.insert(last_shortened_stone+x-last_stone);
                last_shortened_stone+=x-last_stone;
            }
            last_stone=x;
        }
        //printf("l=%d\n", l);
        f[0] = 0;
        for (int i=s; i<t; ++i) {
            f[i] = (stones.find(i)!=stones.end())?1:0;
        }
        for (int i=t; i<=l+t-1; ++i) {
            bool has_stone = (stones.find(i)!=stones.end())?1:0;
            for (int j=i-t; j<=i-s; ++j) {
                f[i]=min(f[i], f[j]+has_stone);
            }
        }
        int ans=INT_MAX;
        for (int i=l; i<=l+t-1; ++i) {
            ans=min(ans, f[i]);
        }
        cout<<ans;
    }
}
