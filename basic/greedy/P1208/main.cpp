#include <bits/stdc++.h>
using namespace std;
struct Farmer {
    int p, a;
    bool operator<(Farmer &second) {
        return p<second.p;
    }
} farmer[2000005];
int n, m;
int main() {
    scanf("%d%d", &n, &m);
    for (int i=1; i<=m; ++i) {
        scanf("%d%d", &farmer[i].p, &farmer[i].a);
    }
    sort(farmer+1, farmer+m+1);
    int cost=0;
    for (int i=1;; ++i) {
        if (n>farmer[i].a) {
            n-=farmer[i].a;
            cost+=farmer[i].a * farmer[i].p;
        } else {
            cost += n * farmer[i].p;
            break;
        }
    }
    printf("%d", cost);
}

