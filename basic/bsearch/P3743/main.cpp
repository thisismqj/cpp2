#include <bits/stdc++.h>
using namespace std;
int n, p;
struct Device {
    int consume;
    int available;
} devices[100005];
bool cond(double t) { // 充电宝p功率能够坚持t秒
    double need_p = 0.f;
    for (int i=1; i<=n; ++i) {
        if (devices[i].consume * t > devices[i].available) {
            need_p += devices[i].consume - devices[i].available/t;
        }
    }
    return need_p <= p;
}
int main() {
    scanf("%d%d", &n, &p);
    for (int i=1; i<=n; ++i) {
        scanf("%d%d", &devices[i].consume, &devices[i].available);
    }
    double l = 0., r = 4294967296ULL;
    while (r-l > 1e-5) {
        double mid = (l+r) / 2;
        if (cond(mid)) l = mid;
        else r = mid;
    }
    if (r > UINT32_MAX) {
        printf("-1");
    } else {
        printf("%f", r);
    }
    return 0;
}

