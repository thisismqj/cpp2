#include <bits/stdc++.h>
using namespace std;
int n, x;
int f[1000005];
int main() {
    cin>>n>>x;
    if (n<x) {
        cout<<"0";
        return 0;
    }
    int sum=0;
    f[x] = 1;
    sum++;
    for (int i=10; i<=n; ++i) {
        int num = i%10;
        f[i] = f[i/10] + (num==x);
        sum+=f[i];
    }
    cout<<sum;
    return 0;
}
