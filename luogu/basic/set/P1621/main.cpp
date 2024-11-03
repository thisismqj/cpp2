#include <bits/stdc++.h>
using namespace std;
int nxt[100005];
int prime[10000];
int a, b, p;
int find_head(int x) {
    if (nxt[x] == x) return x;
    else return nxt[x] = find_head(nxt[x]);
}
bool same_set(int a, int b) {
    return find_head(a)==find_head(b);
}
void cmb(int a, int b) {
    nxt[find_head(b)] = find_head(a);
}
bool ok(int a, int b) {
    // 二分，找到_p<=g
    // p<=_p， ok
    int g = gcd(a, b);
    int l=0, r=9592;
    while (l<r) {
        int mid = (l+r)>>1;
        if (prime[mid]<=g) l = mid+1;
        else r=mid;
    }
    for (int i=l-1; i>=0&&prime[i]>=p; --i) {
        int _p = prime[i];
        if ((a%_p==0)&&(b%_p==0)) return true;
    }
    return false;
}
bool isPrime(int x) {
    for (int i=2; i*i<=x; ++i) {
        if (x%i==0) return false;
    }
    return true;
}
int main() {
    // genprime
    for (int i=2, j=0; i<=100000; ++i) {
        if (isPrime(i)) prime[j++] = i;
    }
    //
    scanf("%d%d%d", &a, &b, &p);
    for (int i=a;i<=b;++i)
        nxt[i] = i;
    int n = b-a+1;
    for (int i=a; i<=b-1; ++i) {
        for (int j=i+1; j<=b; ++j) {
            if (!same_set(i, j)) {
                if (ok(i, j)) {
                    cmb(i, j);
                    --n;
                }
            }
        }
    }
    printf("%d", n);
    return 0;
}
