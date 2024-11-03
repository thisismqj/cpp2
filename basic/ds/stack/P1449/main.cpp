#include <bits/stdc++.h>
using namespace std;
char s[55];
int p=0;
int len;
long long st[32];
int sp=0;
int read(int &m) {
    int ch=s[p++];
    int result;
    if (('0'<=ch&&ch<='9')) {
        m = 0;
        --p;
        int suc = sscanf(s+p, "%lld", &result);
        if (suc==0) {
            m = 1;
            ++p;
            return '-';
        }
        int i;
        int x = result;
        for (i=0; x!=0; x/=10, ++i);
        if (i==0) i=1;
        p+=i;
        ++p;
        return result;
    } else if (ch=='@') {
        m = 2;
        return 0;
    } else {
        m = 1;
        return ch;
    }
}
int main() {
    scanf("%s", s);
    len = strlen(s);
    int mode; // 0: num 1: sym 2: @
    int ch;
    while (true) {
        ch = read(mode);
        if (mode==0) {
            st[sp++] = ch;
        } else if (mode==1) {
            switch(ch) {
            case '+':
                st[sp-2] = st[sp-2]+st[sp-1];
                --sp;
                break;
            case '-':
                st[sp-2] = st[sp-2]-st[sp-1];
                --sp;
                break;
            case '*':
                st[sp-2] = st[sp-2]*st[sp-1];
                --sp;
                break;
            case '/':
                st[sp-2] = st[sp-2]/st[sp-1];
                --sp;
                break;
            }
        } else break;
    }
    printf("%d", st[0]);
    return 0;
}
