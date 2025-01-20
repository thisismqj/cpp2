#include <bits/stdc++.h>
using namespace std;
char s[105];
int len;
void flip(int i, int j) {
    for (;i<j; ++i,--j) {
        char tmp = s[j]; s[j]=s[i]; s[i]=tmp;
    }
}
void solve(int i) {
    if (i>=len)return;
    int st;
    for (st=i; s[st]=='0'&&st<len-1; ++st);
    if (st>=len-1) return;
    int mi=-1, mc=0, cc=0;
    for (int j=st+1; j<len; ++j) {
        if (s[j]=='1') {
            if (cc>mc) {
                mc=cc;
                mi = j-1;
            }
            cc=0;
        } else {
            ++cc;
        }
    }
    if (cc>mc) {
        mc=cc;
        mi=len-1;
    }
    if (mi==-1) return;
    else {
        flip(st, mi);
        solve(mi+1);
    }
}
int main() {
    cin>>s;
    len = strlen(s);
    solve(0);
    cout<<s;
}
