#include <bits/stdc++.h>
using namespace std;
int id[128];
const int mod=10007;
int arr[mod], _ap;
bool bucket[mod];
void p_h() {
    char ch=0;
    int ans=0;
    for (int i=1; i<=8; ++i)
        for (int j=1; j<=8; ++j) {
            while (id[ch]=0) {
                cin>>ch;
            }
            ans=(ans*13+id[ch])%mod;
        }
    bucket[ans]++;
    if (bucket[ans]==1) {arr[_ap++] = ans;}
}
int main() {
    // init_id
    id['*']=1, id['k']=2, id['K']='3', id['p']=4, id['P']=5,id['r']=6,
id['R']=7,id['b']=8,id['B']=9,id['n']=10,id['N']=11, id['q']=12, id['Q']=13;
    //
    int n;
    cin>>n;
    for (int i=1; i<=n; ++i) {
        p_h();
    }
    for (int i=0; i<_ap; ++i) {
        cout<<bucket[arr[i]]<<endl;
    }
    return 0;
}

