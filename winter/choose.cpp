#include <bits/stdc++.h>
using namespace std;
bool is_prime(int x) {
    for (int i=2; i*i<=x; ++i) {
        if (x%i==0) return false;
    }
    return true;
}
int n, k;
int arr[25];
int cnt=0;
void dfs(int p, int dep, int sum) {
    if (dep>=k) {
        if (is_prime(sum)) ++cnt;
        return;
    }
    for (int i=p; i<=n-k+1+dep; ++i) {
        dfs(i+1, dep+1, sum+arr[i]);
    }
}
int main() {
    cin>>n>>k;
    for (int i=1; i<=n; ++i) {
        cin>>arr[i];
    }
    dfs(1, 0, 0);
    cout<<cnt;
    return 0;
}