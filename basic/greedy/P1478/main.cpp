#include <bits/stdc++.h>
using namespace std;
int max_height;
struct Apple {
    int x, y;
    bool operator<(Apple &rt) {
        if (x>max_height) return false;
        if (rt.x>max_height) return true;
        return (y<rt.y);
    }
} apples[5005];
int main() {
    for (int i=1; i<=5004; ++i)
        apples[i].y=-2147483648;
    int n, s, a, b;
    scanf("%d%d", &n, &s);
    scanf("%d%d", &a, &b);
    max_height=a+b;
    for (int i=1;i<=n;++i) {
        scanf("%d", &apples[i].x);
        scanf("%d", &apples[i].y);
    }
    sort(apples+1, apples+1+n);
    int cnt=0;
    s-=apples[1].y;
    for (int i=2;s>=0;++i) {
        ++cnt;
        s-=apples[i].y;
    }
    printf("%d", cnt);
}

