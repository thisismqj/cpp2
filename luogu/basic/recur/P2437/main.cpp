#include <bits/stdc++.h>
using namespace std;
// g(m, n) = f(1, 1+m-n)
struct BigInt {
    int digits[500];
    int len = 0;
    void flatten() {
        int carry = 0;
        for (int i=0; i<500; ++i) {
            digits[i]+=carry;
            carry = digits[i]/10;
            digits[i]%=10;
        }
        for (; digits[len-1]==0;--len);
    }
    BigInt operator*(int second) {
        BigInt result;
        result.len=len+10;
        for (int i=0; i<len; ++i) {
            result.digits[i] = digits[i]*second;
        }
        result.flatten();
        return result;
    }
    BigInt &operator*=(int second) {
        len+=10;
        for (int i=0; i<len; ++i) {
            digits[i]*=second;
        }
        flatten();
        return *this;
    }
    BigInt operator+(BigInt& second) {
        BigInt result;
        result.len = max(len, second.len)+1;
        for (int i=0; i<result.len; ++i) {
            if (i<len) result.digits[i]+=digits[i];
            if (i<second.len) result.digits[i] += second.digits[i];
        }
        result.flatten();
        return result;
    }
    BigInt operator+(int second) {
        BigInt result;
        result.len = len+10;
        result.digits[0]+=second;
        result.flatten();
        return result;
    }
    BigInt &operator+=(int second) {
        len = len+10;
        digits[0]+=second;
        flatten();
        return *this;
    }
    BigInt(BigInt &second) {
        clear();
        len = second.len;
        for (int i=0; i<len; ++i) {
            digits[i]=second.digits[i];
        }
    }
    BigInt() {
        clear();
    }
    BigInt(int value) {
        clear();
        len = 10;
        digits[0]=value;
        flatten();
    }
    void clear() {
        len=0;
        for (int i=0; i<500; ++i) {
            digits[i] = 0;
        }
    }
    void print() {
        if (len==0) {
            putchar('0');
            return;
        }
        for (int i=len-1; i>=0; --i) {
            putchar(digits[i]+'0');
        }
    }
};
int main() {
    BigInt llast(1), last(1), current(2);
    int m,n,x;
    scanf("%d%d", &m, &n);
    x = 1+n-m;
    for (int i=3; i<=x; ++i) {
        current = llast + last;
        llast = last;
        last = current;
    }
    current.print();
}

