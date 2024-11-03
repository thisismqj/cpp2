#include <bits/stdc++.h>
using namespace std;
string s;
unsigned long long n;
int len;
char cow(unsigned long long i) { // 返回(sz)cow字符串中s[i]的值
    if (i<=len) return s[(i)-1];
    unsigned long long sz;
    for (sz=len; sz<i; sz*=2); // sz>=i
    unsigned long long hsz=sz>>1;
    // i变换: i->(i-hsz-1) if i>= hsz+2
    //       i->(i-1) if i==hsz+1
    if (i==hsz+1) return cow(hsz);
    else return cow(i-hsz-1);
}
int main() {
    cin >> s >> n;
    len = s.size();
    cout << cow(n);
}

