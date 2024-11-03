#include <bits/stdc++.h>
using namespace std;
// to find the sum of scores((x+z)*(Nx+Nz)), Cx = Cz, z-x is even
// separate odds and evens
// for any set, any 2 numbers(same color are needed)
// place a bucket, color as index, contents are Indexs
// for any available color in a bucket, apply the algo and acc the sum
// Index ->(a_i) Number
// an array of same color, the question is to solve sum of scores((x+z)*(Nx+Nz))
int a[100005]; // i->N[i]
set<int> colors[2]; // colors of odd/even
vector<int> ind[100005][2]; // colors2ind odd/even
int n, m;
int calc(vector<int>& v) {
    unsigned long long ans=0;
    int m=v.size();
    unsigned long long sum=0;
    for (int i:v) sum+=i;
    for (int i:v) {
        ans+=(((m-2)*i+sum) * a[i]);
        ans%=10007;
    }
    return ans;
}
int main() {
    scanf("%d%d", &n, &m);
    // fill a, colors, ind
    for (int i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i=1; i<=n; ++i) {
        int x;
        scanf("%d", &x);
        colors[i%2].insert(x);
        ind[x][i%2].push_back(i);
    }
    unsigned long long ans=0;
    // iter colors of odd/even
    // for any color, get vector
    // ans+=calc(vector)
    for (int c: colors[0]) {
        ans+=calc(ind[c][0]);
    }
    ans%=10007;
    for (int c: colors[1]) {
        ans+=calc(ind[c][1]);
    }
    ans%=10007;
    printf("%llu", ans);
    return 0;
}
