#include <bits/stdc++.h>
using namespace std;
int s[10];
int b[10];
int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; ++i)
        scanf("%d %d", &s[i], &b[i]);
    int bin=1, min=INT_MAX;
    for (; bin<=((1<<n)-1); ++bin) {
        int sour=1, bitter=0;
        for (int i=0; i<n; ++i) {
            if (bin&(1<<i)) {
                sour*=s[i];
                bitter+=b[i];
            }
        }
        int diff=abs(sour-bitter);
        if (diff<min) min = diff;
    }
    printf("%d", min);
}

