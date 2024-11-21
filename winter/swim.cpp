#include <bits/stdc++.h>
using namespace std;
double step=2;
double s;
int main() {
    cin>>s;
    int cnt=0;
    while (s>=0) {
        s-=step;
        step*=.98;
        ++cnt;
    }
    cout<<cnt;
    return 0;
}
