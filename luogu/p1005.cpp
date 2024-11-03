#include <bits/stdc++.h>
using namespace std;
struct BigInt {
    int arr[1000], l=0;
    BigInt() {
        memset(arr, 0, sizeof(arr));
    }
    BigInt &operator=(int i) {
        memset(arr, 0, sizeof(arr));
        l=1;
        arr[0] = i;
        carry();
        return *this;
    }
    BigInt(const BigInt &b2) {
        memset(arr, 0, sizeof(arr));
        l = b2.l;
        for (int i=0; i<l; ++i) {
            arr[i] = b2.arr[i];
        }
    }
    void carry() {
        int c=0;
        int i=0;
        for (; !(i>=l&&c==0); ++i) {
            arr[i]+=c;
            c=arr[i]/10000;
            arr[i]%=10000;
        }
        l = i;
    }
    BigInt operator+(BigInt &b2) {
        BigInt result;
        result.l = max(l, b2.l);
        for (int i=0;i<result.l;++i) {
            result.arr[i] = arr[i]+b2.arr[i];
        }
        result.carry();
        return result;
    }
    BigInt operator+(int i2) {
        BigInt result=*this;
        result.arr[0] += i2;
        result.carry();
        return result;
    }
    BigInt operator*(int i2) {
        BigInt result;
        result.l = l;
        for (int i=0;i<result.l;++i) {
            result.arr[i] = arr[i]*i2;
        }
        result.carry();
        return result;
    }
    bool operator<(BigInt &b2) {
        if (l!=b2.l) return l < b2.l;
        for (int i=l-1; i>=0; --i) {
            if (arr[i]!=b2.arr[i]) return arr[i] < b2.arr[i];
        }
        return false;
    }
    void print() {
        if (l==0) {
            printf("0");
            return;
        }
        printf("%d", arr[l-1]);
        for (int i=l-2; i>=0; --i) {
            if (arr[i]==0) printf("0000");
            else {
                int j=1;
                int x = arr[i];
                while (x/=10) ++j;
                for (int k=1; k<=4-j; ++k) putchar('0');
                printf("%d", arr[i]);
            }
        }
    }
};
BigInt ans;
int n, m;
int arr[85];
BigInt dp[85][85];
int main() {
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j) {
            scanf("%d", &arr[j]);
        }
        for (int k=1;k<=m;++k) dp[k][k] = 2*arr[k];
        for (int l=2; l<=m; ++l) {
            for (int st=1; st+l-1<=m; ++st) {
                BigInt b1 = dp[st+1][st+l-1]*2+2*arr[st];
                BigInt b2 = dp[st][st+l-2]*2+2*arr[st+l-1];
                dp[st][st+l-1] = b1<b2?b2:b1;
            }
        }
        ans=ans+dp[1][m];
    }
    ans.print();
    return 0;
}

