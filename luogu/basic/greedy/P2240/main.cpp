#include <bits/stdc++.h>
using namespace std;
int n, t;
struct Heap {
    int m;
    int v;
    bool operator<(Heap &h2) {
        return (float)v / m < (float)h2.v / h2.m;
    }
} heaps[105];
int main() {
    scanf("%d%d", &n, &t);
    for (int i=0; i<n; ++i) {
        scanf("%d%d", &heaps[i].m, &heaps[i].v);
    }
    float ans=0.f;
    sort(heaps, heaps+n);
    for (int i=n-1; i>=0; --i) {
        if (t>=heaps[i].m) {
            ans+=heaps[i].v;
            t-=heaps[i].m;
        } else {
            ans+=(float)(heaps[i].v*(t)) / heaps[i].m;
            break;
        }
    }
    printf("%.2f", ans);
}

