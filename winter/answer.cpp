#include <bits/stdc++.h>
using namespace std;
int n, q;
int zero[200005], _zp=0;
void r_n(int *a) {
    *a=0;
    char ch=getchar();
    int sym=(ch=='-'?-1:1);
    if (ch=='+'||ch=='-') ch=getchar();
    do {
        *a=*a*10+ch-'0';
        ch=getchar();
    } while ('0'<=ch&&ch<='9');
    *a*=sym;
    //cout<<"read"<<*a<<endl;
}
int main() {
    cin>>n>>q;
    getchar();
    for (int i=1; i<=n; ++i) {
        int a=0, b=0, c=0;
        r_n(&a);
        r_n(&b);
        r_n(&c);
        int x=(c-b)/a;
        if (a*x+b==c) zero[_zp++] = x;
    }
    sort(zero, zero+_zp);
    int i=0, j=0;
    while (j<_zp) {
        while (zero[i]==zero[j]&&j<_zp)++j;
        zero[++i]=zero[j];
    }
    _zp = i;
    for (int i=1; i<=q; ++i) {
        int l, r;
        cin>>l>>r;
        int cnt=0;
        for (int i=0; zero[i]<=r&&i<_zp; ++i) {
            if (zero[i]>=l) ++cnt;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
