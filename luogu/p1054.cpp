#include <bits/stdc++.h>
using namespace std;
enum Type {SYM, NUM, POLY, NONE};
const int poly_maxn = 105;
int _tlen, _sp;
int bst[35], _bsp=0;
struct Poly {
    int a[poly_maxn];
    Poly(int x) {memset(this, 0, sizeof(Poly));a[0] = x;}
    Poly() {memset(this, 0, sizeof(Poly));}
    Poly(const Poly& b) {memcpy(this, &b, sizeof(Poly));}
    Poly operator+(Poly &b) {
        Poly ans;
        for (int i=0; i<poly_maxn; ++i) {
            ans.a[i] = a[i]+b.a[i];
        }
        return ans;
    }
    Poly operator-(Poly &b) {
        Poly ans;
        for (int i=0; i<poly_maxn; ++i) {
            ans.a[i] = a[i]-b.a[i];
        }
        return ans;
    }
    Poly operator*(Poly &b) {
        Poly ans;
        int maxn;
        int len=poly_maxn;
        while (len>0&&a[len-1]==0) --len;
        maxn = len;
        len=poly_maxn;
        while (len>0&&b.a[len-1]==0) --len;
        maxn+=len;
        for (int i=0; i<maxn; ++i) {
            for (int j=0; j<=i; ++j) {
                ans.a[i] += a[j]*b.a[i-j];
            }
        }
        return ans;
    }
    void pow(int exp) {
        Poly self = *this;
        for (int i=1; i<exp; ++i) {
            *this = *this * self; 
        }
    }
    bool operator==(const Poly &b) {
        for (int i=0; i<poly_maxn; ++i) {
            if (a[i]!=b.a[i]) return false;
        }
        return true;
    }
};
const int max_token = 205;
struct Token {
    enum Type type = SYM;
    Poly *val;
    int num;
    char sym;
} tokens[max_token];
void read() {
    char ch;
    while ((ch=getchar())=='\n');
    do {
        start:
        if (ch=='\n') return;
        if (ch==' ') continue;
        if ('0'<=ch&&ch<='9') {
            int val = ch-'0';
            for(;;) {
                ch=getchar();
                if ('0'<=ch&&ch<='9')
                    val = val*10 + ch-'0';
                else break;
            }
            tokens[_tlen++] = {type:NUM, num:val};
            goto start;
        }
        tokens[_tlen++] = {type:SYM, sym:ch};
    } while ((ch=getchar())!=EOF);
}
int nxt_token(int p) {
    // -1 if not exist
    int i;
    for (i=p+1; i<max_token&&tokens[i].type==NONE; ++i) ;
    if (i>=max_token) return -1; else return i;
}
int pre_token(int p) {
    int i;
    for (i=p-1; i>=0&&tokens[i].type==NONE; --i);
    return i;
}
int to_poly(int l, int r) {
    // 处理括号
    for (int i=l; i<=r; ++i) {
        if (tokens[i].type==SYM && tokens[i].sym=='(') {
            bst[_bsp++] = i;
        }
        if (tokens[i].type==SYM && tokens[i].sym==')') {
            int l = bst[--_bsp];
            tokens[l].type=NONE;
            tokens[i].type=NONE;
            to_poly(l+1, i-1);
        }
    }
    // num, 字母 转poly
    for (int i=l; i<=r; ++i) {
        if (tokens[i].type==NUM) {
            tokens[i].type=POLY;
            tokens[i].val = new Poly(tokens[i].num);
        } else if (tokens[i].type==SYM && tokens[i].sym=='a') {
            tokens[i].type=POLY;
            tokens[i].val = new Poly();
            tokens[i].val->a[1] = 1;
        }
    }
    // 处理幂次
    for (int i=l; i<=r; ++i) {
        if (tokens[i].type==SYM && tokens[i].sym=='^') {
            int p = pre_token(i), n = nxt_token(i);
            tokens[p].val->pow(tokens[n].num);
            tokens[i].type = NONE;
            tokens[n].type = NONE;
        }
    }
    // 处理乘法
    for (int i=l; i<=r; ++i) {
        if (tokens[i].type==SYM && tokens[i].sym=='*') {
            int p = pre_token(i), n = nxt_token(i);
            *tokens[p].val = *tokens[p].val * (*tokens[n].val);
            tokens[i].type = NONE;
            tokens[n].type = NONE;
        }
    }
    // 处理加法
    for (int i=l; i<=r; ++i) {
        if (tokens[i].type==SYM && (tokens[i].sym=='+'||tokens[i].sym=='-')) {
            int p = pre_token(i), n = nxt_token(i);
            *tokens[p].val = tokens[i].sym=='+' ? *tokens[p].val + (*tokens[n].val) : *tokens[p].val - (*tokens[n].val);
            tokens[i].type = NONE;
            tokens[n].type = NONE;
        }
    }
    return nxt_token(l-1);
}
Poly poly_handler() {
    read();
    int p = to_poly(0, _tlen-1);
    Poly ans = *tokens[p].val;
    for (int i=0; i<_tlen; ++i) {
        if (tokens[i].type==POLY) free(tokens[i].val);
    }
    _tlen=0;
    return ans;
}
int main() {
    Poly prob = poly_handler();
    int n;
    cin>>n;
    for (int i=0; i<n; ++i) {
        if (prob==poly_handler()) {
            putchar('A'+i);
        }
    }
}
