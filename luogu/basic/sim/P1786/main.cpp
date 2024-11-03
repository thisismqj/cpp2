#include <bits/stdc++.h>
using namespace std;
struct BigInt {
    int digit[10000];
    int len; // 0 是0位捏
    void print() {
        if (len==0) putchar('0');
        else
            for (int i=len-1; i>=0; --i) {
                putchar(digit[i]+'0');
            }
    }
    void set(int i) {
        len +=10;
        digit[0] = i;
        int carry=0;
        for (int j=0; j<len; ++j) {
            carry = (carry+digit[j])/10;
            digit[j] = (carry+digit[j])%10;
        }
        for (;digit[len-1]==0;--len);
    }
    BigInt() = default;
    BigInt(BigInt &src) {
        len = src.len;
        for (int i=0; i<len; ++i) {
            digit[i] = src.digit[i];
        }
    }
    void operator*=(int second) {
        len+=10;
        int carry=0;
        // 乘，进位，直到digit为0和进位为0, 递增位数
        for (int i=0; i<=len; ++i) {
            int num = digit[i];
            digit[i] = (carry+num*second) % 10;
            carry = (carry+num*second) /10;
        }
        for (;digit[len-1]==0;--len);
    }
    void clear() {
        for (int i=0; i<len+10; ++i) digit[i]=0;
        len=0;
    }
} prod;
int main() {
    int t, n, a;
    cin >> t;
    for (; t>0; --t) {
        prod.set(1);
        cin >> n >> a;
        for (int i=2; i<=n; ++i) {
            prod *= i;
        }
        int cnt=0;
        for (int i=0; i<prod.len; ++i) {
            if (prod.digit[i]==a) ++cnt;
        }
        cout << cnt << endl;
        prod.clear();
    }
}

