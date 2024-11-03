#include <bits/stdc++.h>
using namespace std;
int a; // 月付
int p; // 本金
int m; // m期
inline float f(float ans) {
    float q = 1 / (1+ans);
    return a * q * (1-pow(q, m)) / (1-q);
}
int main() {
    scanf("%d%d%d", &p, &a, &m);
    float l = 0, r = 3.;
    while (r-l>.0001) {
        float mid = (l+r) /2;
        if (f(mid) < p) r = mid;
        else l = mid;
    }
    printf("%.1f", l * 100);
    return 0;
}

