#include <bits/stdc++.h>
using namespace std;
void swap(int &a, int &b) {int tmp=a; a=b; b=tmp;}
int main() {
    int a, b, c;
    cin>>a>>b>>c;
    if (a>b) {
        swap(a, b);
    }
    if (a>c) {
        swap(a, c);
    }
    if (c<b) {
        swap(c, b);
    }
    cout<<a<<' '<<b<<' '<<c;
    return 0;
}
