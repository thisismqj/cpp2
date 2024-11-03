#include <bits/stdc++.h>
using namespace std;
char inp[100];
int cap[] = {0, 0, -32};
void f_c(char c, int p2) {
    for (;p2>0;--p2)
        putchar(c);
}
void f(int l, int r, int p1, int p2, int p3) {
    if (p1==3) {
        for (int i=0; i<(inp[r]-inp[l]-1)*p2; ++i) {
            putchar('*');
        }
        return;
    }
    if (inp[l]>='0'&&inp[l]<='9') p1=0;
    if (p3==1) {
        for (char c=inp[l]+1; c<=inp[r]-1; ++c) {
            f_c(c+cap[p1], p2);
        }
    } else {
        for (char c=inp[r]-1; c>=inp[l]+1; --c) {
            f_c(c+cap[p1], p2);
        }
    }
}
int main() {
    int p1, p2, p3, i;
    cin >> p1 >> p2 >> p3;
    cin >> inp;
    int len = strlen(inp);
    putchar(inp[0]);
    for (i=1; i<=len-2; ++i) {
        if (inp[i]=='-' && inp[i-1]<inp[i+1] && inp[i+1]-inp[i-1]<=122-97 && inp[i-1]>='0') {
            f(i-1, i+1, p1, p2, p3);
        } else {
            putchar(inp[i]);
        }
    }
    putchar(inp[i]);
}

