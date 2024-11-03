#include <bits/stdc++.h>
using namespace std;
double d1, c, d2, p; int n;
double idist[10], price[10], f[10];
double d2p;
int stopi[10];// 按油价从低到高排的车站下标索引[0, n]
// 初始化: stopi[i] = i
// 获取价格: price[stopi[i]]
// cmp: rt
bool cmp(int i1, int i2) {
    return price[i1] < price[i2];
}
int main() {
    scanf("%lf%lf%lf%lf%d", &d1, &c, &d2, &p, &n);
    price[0] = p;
    d2p = 1/d2;
    // stopi初始化
    for (int i=0; i<=n; ++i) {
        stopi[i] = i;
    }
    for (int i=1; i<=n; ++i) {
        scanf("%lf%lf", &idist[i], &price[i]);
    }
    // stopi排序
    sort(stopi, stopi+n+1, cmp);
    // 站: [0, n+1]
    idist[n+1] = d1; // i站到0站的距离
    // 初始化f
    for (int i=1; i<=n+1; ++i) {
        f[i] = -(idist[i]*d2p);
    }
    double sump = 0;
    for (int i=0; i<=n; ++i) {
        double min_o = INT_MAX;
        for (int j=stopi[i]; j<=n+1; ++j) {
            min_o = min(min_o, c-f[j]+min(0., f[stopi[i]]));
        }
        double addo = min(min(min_o, c-max(0., f[stopi[i]])), -f[n+1]+min(0., f[stopi[i]]));
        sump+=addo*price[stopi[i]];
        for (int j=stopi[i]; j<=n+1; ++j) {
            f[j]+=addo;
        }
    }
    bool succ = true;
    for (int i=1; i<=n+1; ++i) {
        if (f[i]<-0.01) {succ=false; break;}
    }
    if (succ) {
        printf("%.2lf", sump);
    } else {
        printf("No Solution");
    }
    return 0;
}

