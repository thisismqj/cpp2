#include <bits/stdc++.h>
using namespace std;
int n;
int d[100005];
int days;
// recursively calc the days 
// find the min
// -min, add days
// recursively
void calc(int l, int r) {
    int min=INT_MAX, min_index[100005];
    int p=0;
    if (l==r) {days+=d[l];return;}
    for (int i=l; i<=r; ++i) {
        if (d[i]<min) {
            min = d[i];
            p=1; // clear
            min_index[0] = i;
        } else if (d[i]==min) {
            min_index[p++]=i; // append
        }
    }
    days+=min;
    for (int i=l; i<=r; ++i)
        d[i]-=min;
                // 0_pass -> (locate l)find_r -> 0_pass
    int last=l-1;
    for (int i=0;i<p;++i) {
        if (min_index[i]-last > 1) {
            calc(last+1, min_index[i]-1);
        }
        last=min_index[i];
    }
    if (r-min_index[p-1]>=1) calc(min_index[p-1]+1, r);
}

int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; ++i)
        scanf("%d", &d[i]);
    calc(1, n);
    printf("%d", days);
}

