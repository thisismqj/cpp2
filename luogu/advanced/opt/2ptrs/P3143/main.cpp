#include <bits/stdc++.h>
using namespace std;
int dsz[50005];
struct Data{
    int l, r, n;
} ddata[1000000];
bool cmp(Data &d1, Data &d2) {
    if (d1.n!=d2.n) return d1.n > d2.n;
    return d1.l < d2.l;
}
int _dp = 0;
int n, k;
void mv(int &p) {
    int v = dsz[p];
    while (p<=n&&v==dsz[p]) ++p;
}
int sk(int l, int r) {
    if (r==l) return 0;
    return dsz[r-1]-dsz[l];
}
bool crash(Data &d1, Data &d2) {
    int max_l  = max(d1.l, d2.l);
    int min_r = min(d1.r, d2.r);
    return max_l<min_r;
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i=1; i<=n; ++i) {
        scanf("%d", &dsz[i]);
    }
    sort(dsz+1, dsz+1+n);
    int l=1, r=1;
    while (sk(l, r)<=k) {
        ddata[_dp++] = {l, r, r-l};
        mv(r);
    }
    while (r!=n+1) {
        if (sk(l, r)>k) mv(l);
        else {
            ddata[_dp++] = {l, r, r-l};
            mv(r);
        }
    }
    while (sk(l, r)>k) mv(l);
    while (l!=n+1) {
        ddata[_dp++] = {l, r, r-l};
        mv(l);
    }
    sort(ddata, ddata+_dp, cmp);
    Data &d1 = ddata[0];
    int dp=0;
    while (dp!=n+1&&ddata[0].n==ddata[dp++].n) ;
    --dp;
    Data &d2 = ddata[dp];
    int n2=0;
    for (int i=1; i<n; ++i) {
        if (!crash(d1, ddata[i])) {
            n2 = ddata[i].n;
            break;
        }
    }
    int max1 = d1.n+n2;
    n2=0;
    for (int i=0; i<n; ++i) {
        if (!crash(d2, ddata[i])) {
            n2 = ddata[i].n;
            break;
        }
    }
    int max2 = d2.n+n2;
    printf("%d", max(max1, max2));
    return 0;
}
