#include <bits/stdc++.h>
using namespace std;
struct BigInt {
    int digits[105];
    int len;
    BigInt(const BigInt &b) {
        memcpy(this, &b, sizeof(BigInt));
    }
    BigInt() {
        clear();
    }
    void clear() {
        memset(this, 0, sizeof(BigInt));
    }
    void flatten(int maxn=-1) {
        int carry = 0;
        len = 0;
        while (len<=100&&(maxn==-1||len<maxn)) {
            digits[len]+=carry;
            carry = digits[len]/10;
            digits[len]%=10;
            ++len;
            //printf("len:%d\n", len);
        }
        while (digits[len-1]==0) --len; 
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
        ans.flatten(maxn);
        return ans;
    }
    BigInt mul_int(int b) {
        BigInt ans = *this;
        for (int i=0; i<len; ++i) {
            ans.digits[i]*=b;
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
                num[i+1] = mul(maxn, num[i+1]);
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
} n, tn, base, ans;
int k, f[105], chk[10];
int main() {
    n.read();
    scanf("%d", &k);
    f[0] = 1;
    ans.digits[0]=1;ans.len=1;
    for (int j=1; j<=k; ++j) {
        memset(chk, 0, sizeof(chk));
        base=n;
        for (int i=1; i<j; ++i) {
            base=base.pow(j, f[i]);
        }
        //printf("j=%d:\n", j);
        for (int i=1;; ++i) {
            tn = base.pow(j, i).mul(j, n);
            //putchar('\t');
            //tn.print();
            //putchar('\n');
            if (tn.digits[j-1]==n.digits[j-1]) {
                f[j] = i;
                break;
            }
            if (chk[tn.digits[j-1]]) {
                printf("-1");
                return 0;
            }
            chk[tn.digits[j-1]] = true;
        }
    }
    for (int i=1; i<=k; ++i) {
        //printf("%d\t", f[i]);
        ans=ans.mul_int(f[i]);
    }
    ans.print();
}
