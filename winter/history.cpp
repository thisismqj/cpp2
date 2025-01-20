#include <bits/stdc++.h>
using namespace std;
char s[1005], t[1005];
int q;
int main() {
    cin>>(s+1)>>(t+1)>>q;
    for (int i=1; i<=q; ++i) {
        int ls, rs, lt, rt;
        cin>>ls>>rs>>lt>>rt;
        for (int i=0; ls+i<=rs && lt+i<=rt; ++i) {
            if (s[ls+i]<t[lt+i]) {
                cout<<"yifusuyi"<<endl;
                goto re;
            } else if (s[ls+i]>t[lt+i]) {
                cout<<"erfusuer"<<endl;
                goto re;
            }
        }
        if (rs-ls==rt-lt) {
            cout<<"ovo"<<endl;
        } else if (rs-ls < rt-lt) {
            cout<<"yifusuyi"<<endl;
        } else {
            cout<<"erfusuer"<<endl;
        }
        re:
    }
}
