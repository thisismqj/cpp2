#include <bits/stdc++.h>
using namespace std;
int st[105];
int p=0;
bool readInt(int &num) {
    char ch=getchar();
    char digit[12];
    int p=0;
    if ('0'<=ch&&ch<='9') {
        num=0;
        digit[p++] = ch-'0';
        while ('0'<=ch&&ch<='9') {
            ch=getchar();
            digit[p++] = ch-'0';
        }
        --p;
        for (int i=0; i<p; ++i) {
            num+=digit[p-1-i]*pow(10, i);
        }
        return true;
    } else {
        num = ch;
        return false;
    }
}
int main() {
    bool sharp = false;
    while (true) {
        int num;
        int op1, op2, op3;
        if (readInt(num)) {
            st[p++] = num;
        } else {
            char ch = num;
            if (ch=='@') break;
            else {
                switch(ch) {
                case '+':
                    op2=st[--p];
                    op1=st[--p];
                    st[p++] = op1+op2;
                    break;
                case '-':
                    op2=st[--p];
                    op1=st[--p];
                    st[p++] = op1-op2;
                    break;
                case '*':
                    op2=st[--p];
                    op1=st[--p];
                    st[p++] = op1*op2;
                    break;
                case '/':
                    op2=st[--p];
                    op1=st[--p];
                    st[p++] = op1/op2;
                    break;
                case '#':
                    if (!sharp) {
                        getchar();
                        sharp = true;
                    } else {
                        op3=st[--p];
                        op2=st[--p];
                        op1=st[--p];
                        st[p++] = (op1+op2) * (op2+op3);
                        sharp = false;
                    }
                    break;
                }
            }
        }
    }
    printf("%d", st[0]);
    return 0;
}
