#include <bits/stdc++.h>
using namespace std;
const int pow2_20=1048576;
const float log10_2=0.301030f;

struct BigInt {
    int digits[1000];
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
    void print_500() {
        for (int i=0; i<10; ++i) {
            for (int j=0; j<50; ++j) {
                int n = 499-(i*50+j);
                putchar('0'+digits[n]);
            }
            putchar('\n');
        }
    }
    void mod_10_pow_500() {
        len = 500;
        for (int i=500; i<1000; ++i) {
            digits[i]=0;
        }
        for (; digits[len-1]==0;--len);
    }
};

int main() {
    BigInt result(1);
    int p;
    cin >> p;
    cout << (int)(p * log10_2)+1 << endl;
    int count_90=0;
    for (int i=0; i<p/20;++i) {
        result *= pow2_20;
        ++count_90;
        if (!(count_90%90)) {
            result.mod_10_pow_500();
        }
    }
    for (int j=0; j<p%20; ++j) {
        result *= 2;
    }
    result.mod_10_pow_500();
    --result.digits[0];
    result.print_500();
}

