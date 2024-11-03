#include <bits/stdc++.h>
using namespace std;
int w,n;
int items[30005];
int main() {
    scanf("%d", &w);
    scanf("%d", &n);
    for (int i=1;i<=n;++i)
        scanf("%d", &items[i]);
    sort(items+1, items+n+1);
    int i=1, j=n, cnt=0;
    while (i<j) {
        if (items[i]+items[j]<=w) {
            ++i;--j;
        } else {
            --j;
        }
        ++cnt;
    }
    if (i==j) ++cnt;
    printf("%d", cnt);
}

