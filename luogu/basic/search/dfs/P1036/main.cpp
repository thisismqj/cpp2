#include <bits/stdc++.h>
using namespace std;
bool isPrime(int x) {
    for (int i=2; i*i<=x; ++i) {
        if ((x%i)==0) return false;
    }
    return true;
}
int n, k;
int arr[25];
int cnt=0;
int sum=0;
void dfs(int depth, int start) {
    if (depth == k+1) {
        cnt += isPrime(sum);
        return;
    }
    for (int i=start; i<=n-(k-depth); ++i) {
        sum += arr[i];
        dfs(depth+1, i+1);
        sum -= arr[i];
    }
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i=1; i<=n; ++i) {
        scanf("%d", &arr[i]);
    }
    dfs(1, 1);
    printf("%d", cnt);
    return 0;
}

