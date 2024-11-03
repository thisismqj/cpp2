#include <bits/stdc++.h>
using namespace std;
char flag[50][51];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; ++i)
        scanf("%s", flag[i]);
    int min_change=2147483647;
    for (int i=0; i<=n-3; ++i)
        for (int j=i+1; j<=n-2; ++j) {
            int k, change=0;
            for (k=0; k<=i; ++k)
                for (int l=0;l<m; ++l) {
                    if (flag[k][l]!='W') ++change;
                }
            for (; k<=j; ++k)
                for (int l=0;l<m; ++l) {
                    if (flag[k][l]!='B') ++change;
                }
            for (; k<=n-1; ++k)
                for (int l=0;l<m; ++l) {
                    if (flag[k][l]!='R') ++change;
                }
            if (change<min_change) min_change = change;
        }
    printf("%d", min_change);
}

