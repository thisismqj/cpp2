#include <bits/stdc++.h>
using namespace std;
double d1, c, d2, p; int n;
double idist[10], price[10];
double d2p;
int main() {
    scanf("%lf%lf%lf%lf%d", &d1, &c, &d2, &p, &n);
    price[0] = p;
    d2p = 1/d2;
    for (int i=1; i<=n; ++i) {
        scanf("%lf%lf", &idist[i], &price[i]);
    }
    // 站: [0, n+1]
    idist[n+1] = d1; // i站到0站的距离
    double fuel = 0.;
    double cost=0.;
    int j=1;
    for (int i=0; i<=n; i=j-1) {
        double old_fuel = fuel;
        for (; price[i]<=price[j-1]; ++j) {
            fuel = d2p * (idist[j] - idist[i]);
            if (fuel > c) {
                fuel = c;
                if (i==j-1) {
                    printf("No Solution");
                    return 0;
                }
                break;
            }
        }
        cost+=price[i]*(fuel - old_fuel);
        fuel -= (idist[j-1] - idist[i]) * d2p;
        if (fuel < 0.) {
            printf("No Solution");
            return 0;
        }
    }
    printf("%.2lf", cost);
    return 0;
}

