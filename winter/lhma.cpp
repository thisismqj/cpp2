#include <bits/stdc++.h>
using namespace std;
int n, x, ptr=0;
int main() {
    cin>>n;
    bool current = 1;
    while (ptr!=n*n) {
        if (x==0) current=!current, cin>>x;
        if (ptr!=0&&ptr%n==0) putchar('\n');
        putchar('0'+current);
        ++ptr; --x;
    }
    return 0;
}
