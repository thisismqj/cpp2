#include <bits/stdc++.h>
using namespace std;
int n, x;
long long candies[100005];
int main() {
    scanf("%d%d", &n, &x);
    for (int i=1;i<=n;++i)
        scanf("%d", &candies[i]);
    unsigned long long cnt=0;
    if (candies[1]>x) {
        cnt+=candies[1]-x;
        candies[1]-=cnt;
    }
    for (int i=2;i<=n;++i) {
        int d=candies[i-1]+candies[i]-x;
        if (d<0) d=0;
        candies[i]-=d;
        cnt+=d;
    }
    printf("%llu", cnt);
}

