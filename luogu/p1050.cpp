#include <bits/stdc++.h>
using namespace std;
struct BigInt {
    int digits[105];
    int len;
    void clear() {
        memset(this, 0, sizeof(BigInt));
    }
    void flatten() {
        int carry = 0;
        len = 0;
        while (true) {
            digits[len]+=carry;
            if (digits[len]==0) break;
            carry = digits[len]/10;
            digits[len]%=10;
            ++len;
            //printf("len:%d\n", len);
        }
    }
    void read() {
        len=0;
        char ch;
        while ((ch=getchar())!=EOF) {
            if ('0'<=ch&&ch<='9') {
                ch-='0';
                digits[len++] = ch;
            } else {
                break;
            }
        }
        for (int i=0; i<len/2; ++i) swap(digits[i], digits[len-1-i]);
        //printf("len:%d\n", len);
    }
    void print() {
        for (int i=0; i<len; ++i) {
            printf("%d", digits[len-1-i]);
        }
    }
    BigInt mul(int maxn, BigInt &b) {
        BigInt ans;
        int ans_len = min(len+b.len, maxn);
        for (int i=0; i<ans_len; ++i) {
            for (int j=max(0, i-b.len+1); j<=min(i, len-1); ++j) {
                ans.digits[i] += digits[j]*b.digits[i-j];
            }
        }
        ans.flatten();
        return ans;
    }
    BigInt pow(int maxn, int exp) {
        int dsp[33], _sp=0;
        BigInt num[33]; int _nsp=1;
        num[0] = *this;
        for (int i=0; i<31; ++i) {
            if (exp&(1<<i)) {
                //printf("exp2^%d\n", i);
                num[_sp+1].digits[0]=1;num[_sp+1].len=1;
                dsp[_sp++] = i;
            }
        }
        for (int i=0; i<_sp; ++i) {
            //printf("dsp%d:%d\n", i, dsp[i]);
            for (int j=1; j<=(1<<dsp[i]); ++j) {
                num[i+1] = num[i].mul(maxn, num[i+1]);
                //num[i+1].print();
                //putchar('\n');
            }
        }
        BigInt ans;
        ans.digits[0]=1;ans.len=1;
        for (int i=1; i<=_sp; ++i) {
            ans = num[i].mul(maxn, ans);
        }
        return ans;
    }
    bool eq(int maxn, BigInt &b) {
        for (int i=0; i<maxn; ++i) if (digits[i]!=b.digits[i]) return false;
        return true;
    }
} cn[105], n, tn;
int k, f[105];
int main() {
    n.read();
    scanf("%d", &k);
    cn[0] = n; f[0]=1;
    for (int j=1; j<=k; ++j) {
        tn.clear();
        tn.digits[0] = 1; tn.len=1;
        int i=0;
        while (true) {
            tn=tn.mul(j, cn[j-1]);
            tn.print();
            putchar('\n');
            ++i;
            if (tn.digits[j-1]==n.digits[j-1]) {
                f[j] = i*f[j-1];
                break;
            }
        }
    }
    printf("%d", f[k]);
}
