#include <bits/stdc++.h>
using namespace std;
int main() {
    // 生成排列bin, 需满足个数条件
    // 满足则输出
    // 字典序捏
    int n, r;
    scanf("%d %d", &n, &r);
    unsigned long long bin=(1<<n)-1;
    for (;bin>=1;--bin) {
        if (__popcount(bin)==r) {
            for (int j=n-1; j>=0; --j) {
                if (bin&(1<<(j+1-1))) printf("%3d", n-j);
            }
            putchar('\n');
        }
    } 
}

