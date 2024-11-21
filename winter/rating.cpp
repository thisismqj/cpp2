#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin>>n;
    int maxs=0, mins=INT_MAX, sum=0;
    for (int i=1; i<=n; ++i) {
        int x;
        cin >>x;
        maxs=max(x, maxs);
        mins=min(x, mins);
        sum+=x;
    }
    sum-=maxs;
    sum-=mins;
    printf("%.2lf", (double)sum/(n-2));
    return 0;
}
