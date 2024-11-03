#include <bits/stdc++.h>
using namespace std;
int m, n;
int sch[100005], stu[100005];
int main() {
    scanf("%d%d", &m, &n);
    for (int i=1;i<=m;++i)
        scanf("%d", &sch[i]);
    for (int i=1;i<=n;++i)
        scanf("%d", &stu[i]);
    // 找到<考生分数的最后一个录取线，及它之后的第一个录取线(l)
    // 如果全>=考生分数，则l应取第一个
    // 以l结束
    // 比较差值，不满意加上小差值
    sort(sch+1, sch+1+m);
    sch[m+1] = 10000000;
    sch[0] = -10000000;
    unsigned long long diff=0;
    for (int i=1; i<=n; ++i) {
        int x = stu[i];
        int l=1, r=m+1;
        while (l<r) {
            int mid = l+(r-l)/2;
            if (sch[mid]<x) l = mid + 1;
            else r = mid;
        }
        int d_1 = abs(sch[l] - x);
        int d_2 = abs(sch[l-1] - x);
        diff += min(d_1, d_2);
    }
    printf("%llu", diff);
    return 0;
}