#include <bits/stdc++.h>
using namespace std;
const int maxn = 105; // 100位 // 可能再冗余
// 高精度
// 需用到高精度乘(幂运算?), 读入, 判等
// 思路
// 对pow(10, k)取模 高精度
// 判等?
// 最小公倍数? dp? 连乘?
// 高精度快速幂? (或许不用) 变量? 不变量? (定制版本)
// 设f[i] 为num[1, i]位的循环长度,
// 每次对num[1, i+1]做f[i]次幂, 直到第k次, num[1, i+1]=原num[1, i+1]
// f[i+1] = k*f[i]
// num[1,i+1] = dig[i+1]*pow(10, i+1)+num[1,i]
// 二项式?
// 只用考察对dig[i+1]的贡献...
// 只和num[1,i]有关(记录循环体?
struct BigInt {
    int digits[maxn]; // 可改char(不tle) // <=81
    int len; // digits[len]=0 // len 0 = 1
    BigInt() {
        len=0;
        memset(digits, 0, sizeof(digits));
    }
    void flatten() {
        // 将溢出的数字抹平
        int carry=0;
        for (int i=0; i<len; ++i) {
            digits[i]+=carry;
            carry = digits[i]/10;
            digits[i]%=10;
        }
        while (carry!=0) {
            digits[len] = carry%10;
            carry/=10;
            ++len;
        }
    }
    BigInt operator+(BigInt &b) {
        BigInt ans;
        for (int i=0; i<max(len, b.len); ++i) {
            ans.digits[i] = digits[i]+b.digits[i];
        }
        ans.len = max(len, b.len);
        ans.flatten();
        return ans;
    }
    BigInt operator*(BigInt &b) {
        BigInt ans;
        for (int i=0; i<len+b.len-1; ++i) {
            // x: 第二排指针
            for (int x=max(0, i-a.len), x<=b.len-1; ++x) {
                ans.digits[i]+=digits[x]*b.digits[i-x];
            }
            ans.flatten(); // 有必要
        }
        ans.flatten();
        return ans;
    }
    BigInt pow(int n) {
        // 尝试快速幂
        // 将n写成2^a1+2^a2...
        // 求出2^a1...相乘
    }
};
int main() {

}
