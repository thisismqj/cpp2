#include <bits/stdc++.h>
using namespace std;
const float deltax = 1e-4;
float a, b, c, d;
inline float f(float x) {return a*x*x*x+b*x*x+c*x+d;}
float solve(float l, float r) {
    // find the min x that f(x) >=0
    while (r-l>=deltax) {
        float mid = (r+l) / 2;
        if (f(mid) >= 0) r = mid;
        else l = mid;
    }
    return l;
}
int main() {
    scanf("%f%f%f%f", &a, &b, &c, &d);
    if (a < 0) {
        a = -a;b = -b; c = -c; d = -d;
    }
    float dx1, dx2;
    {
        float sqrt_delta = sqrt(4*b*b - 4*3*a*c);
        dx1 = (-2*b-sqrt_delta) / (2*3*a);
        dx2 = (-2*b+sqrt_delta) / (2*3*a);
    }
    float x1=solve(-100., dx1);
    float x3=solve(dx2, 100.);
    a = -a;b = -b; c = -c; d = -d;
    float x2=solve(dx1, dx2);
    printf("%.2f %.2f %.2f", x1, x2, x3);
    return 0;
}

