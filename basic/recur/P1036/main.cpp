#include <bits/stdc++.h>
using namespace std;
bool isPrime(int x) {
    if (x<=1) return false;
    for (int i=2; i*i<=x; ++i) {
        if (!(x%i)) return false;
    }
    return true;
}
int n, k;
int nums[25];
int sort_count(int sum_now, int i_now, int depth, int &prime_now) {
    if (depth==0) {
        prime_now+=isPrime(sum_now);
        return 0;
    }
    --depth;
    for (int i=i_now; i<=n-depth; ++i) {
        sort_count(sum_now + nums[i], i+1, depth, prime_now);
    }
    return sum_now;
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i=1; i<=n; ++i) {
        scanf("%d", &nums[i]);
    }
    int prime=0;
    sort_count(0,1,k,prime);
    printf("%d", prime);
}

