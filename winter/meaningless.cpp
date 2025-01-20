#include <bits/stdc++.h>
using namespace std;
int q;
bool np[100005];
int main() {
    cin>>q;
    for (int i=1; i<=q; ++i) {
        int k;
        unsigned long long a;
        cin>>a>>k;
        if (k==1) {
            cout<<a<<endl;
            continue;
        }
        unsigned long long c = a, d=a;
        for (unsigned long long i=2; i*i<=d; ++i) {
            if (!np[i]) {
                for (unsigned long long j=i<<1; j>0&&j*j<=d; j+=i) {
                    np[j]=1;
                }
                // to do with the prime
                unsigned long long l=a, cnt=0;
                while (l%i==0) {++cnt; l/=i; if (cnt>=k) break;}
                while (c%i==0) {c/=i;}
                if (cnt<k) a=l;
            }
        }
        cout<<a/c<<endl;
    }
    return 0;
}
