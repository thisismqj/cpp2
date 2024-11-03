#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[1000005], bucket[1000005];
int main() {
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; ++i) {
        int x;
        scanf("%d", &x);
        arr[i] = x;
    }
    // 一个bucket表示当前的画师对应画的数目，右移时相应增加，左移时相应减少
    // 每次记录长度
    // r右移，直到所有画师有一张画（仅当增加的bucket为0时检测记录有效长度）
    // l右移（记录有效长度）直到无效(左移后该值减为0)
    // r右移，若到n+1还无效则结束
    int l=1, r=1;
    bool full = false;
    int min_len=INT_MAX;
    int min_l=-1, min_r=-1;
    while (true) {
        // r右移
        while (!full&&r<=n) {
            if (bucket[arr[r]]==0) {
                ++bucket[arr[r]];
                full = true;
                for (int i=1;i<=m;++i) {
                    if (!bucket[i]) {full = false;break;}
                }
            } else ++bucket[arr[r]];
            r++;
        }
        if (!full&&r>n) break;
        while (full) {
            --bucket[arr[l]];
            if (bucket[arr[l]]==0) {full=false;}
            ++l;
        }
        int len=r-l+1;
        if (len<min_len) {
            min_len = len;
            min_l = l-1;
            min_r = r-1;
        }
    }
    printf("%d %d", min_l, min_r);
    return 0;
}
