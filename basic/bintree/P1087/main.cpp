#include <bits/stdc++.h>
using namespace std;
int n;
char str[1050];
char rfbi(char *str, int l) {
    bool all0 = true, all1 = true;
    for (int i=0; i<l; ++i) {
        if (str[i]=='1') all0 = false;
        if (str[i]=='0') all1 = false;
    }
    if (all0) return 'B';
    else if (all1) return 'I';
    else return 'F';
}
void fbi(int l, int exp) {
    if (exp==0) {
        putchar(rfbi(str+l, 1));
    } else {
        fbi(l, exp-1);
        fbi(l+(1<<(exp-1)), exp-1);
        putchar(rfbi(str+l, 1<<exp));
    }
}
int main() {
    scanf("%d", &n);
    scanf("%s", str);
    fbi(0, n);
    return 0;
}
