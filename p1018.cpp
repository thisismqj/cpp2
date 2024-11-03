#include <bits/stdc++.h>
using namespace std;
struct BigInt {
    int arr[12], l=0;
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
    BigInt operator*(BigInt &b2) {
        BigInt ans;
        ans.l = l+b2.l-1;
        for (int i=0; i<l; ++i) {
            for (int j=0; j<b2.l; ++j) {
                ans.arr[i+j] += arr[i] * b2.arr[j];
            }
        }
        ans.carry();
        return ans;
    }
    bool operator<(const BigInt &b2) const {
        if (l!=b2.l) return l < b2.l;
        for (int i=l-1; i>=0; --i) {
            if (arr[i]!=b2.arr[i]) return arr[i] < b2.arr[i];
        }
        return false;
    }
    void read(const char *str, int _l) {
        memset(arr, 0, sizeof(arr));
        if (str[0]=='0') {l = 0; return;}
        for (int i=0; i<_l; ++i) {
            arr[i/4] += pow(10, i%4) * (str[_l-1-i] - '0');
        }
        l = (_l-1)/4+1;
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
BigInt f[41][41][7];
int n, k;
char str[50];
int main() {
    scanf("%d%d", &n, &k);
    scanf("%s", str);
    // init f
    for (int i=1; i<=n; ++i) {
        for (int j=i; j<=n; ++j) {
            f[i][j][0].read(str+i-1, j-i+1);
        }
    }
    for (int p=1; p<=k; ++p) {
        for (int i=1; i<=n-p; ++i) {
            for (int j=i+p; j<=n; ++j) {
                for (int x = 0; x<=j-i-p; ++x) {
                    f[i][j][p] = max(f[i][j][p], f[i+x+1][j][p-1] * f[i][i+x][0]);
                }
            }
        }
    }
    f[1][n][k].print();
    return 0;
}
