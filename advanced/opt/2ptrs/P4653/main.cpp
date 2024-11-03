#include <bits/stdc++.h>
using namespace std;
int n;
double ca, cb;
double pa[100005], pb[100005];
bool cmp(double a, double b) {return a>b;}
int _pa = 1, _pb = 1;
int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; ++i) {
        scanf("%lf%lf", &pa[i], &pb[i]);
    }
    sort(pa+1, pa+n+1, cmp);
    sort(pb+1, pb+n+1, cmp);
    double ans = 0.;
    while (true) {
        if (_pa > n || _pb > n) {
            break;
        }
        if (abs(ca-cb)<.00005) {
            ca+=pa[_pa++]-2;
            cb+=pb[_pb++]-2;
            ans = max(ans, min(ca, cb));
        } else if (ca<cb) {
            ca+=pa[_pa++]-1;
            --cb;
            ans = max(ans, min(ca, cb));
        } else {
            cb+=pb[_pb++]-1;
            --ca;
            ans = max(ans, min(ca, cb));
        }
    }
    printf("%.4lf", ans);
    return 0;
}
