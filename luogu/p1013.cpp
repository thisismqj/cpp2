#include <bits/stdc++.h>
using namespace std;
int m;
char arr[12][12][3];
char ch2n[130];
char chpool[12];
int main() {
    scanf("%d", &m);
    int n=m-1;
    for (int i=0; i<m; ++i) {
        for (int j=0; j<m; ++j) {
            scanf("%s", arr[i][j]);
        }
    }
    for (int i=1; i<=n; ++i) {
        char ch = arr[i][0][0];
        chpool[i-1] = ch;
        int cnt=0;
        for (int j=1; j<=n; ++j) {
            cnt+=(strlen(arr[i][j])==2);
        }
        ch2n[ch] = cnt;
    }
    int bset = (1<<n)-1;
    int cbset=0;
    for (int i=0; i<n; ++i) {
        cbset|=(1<<(ch2n[chpool[i]]));
    }
    if (cbset!=bset) {
        printf("ERROR!");
        return 0;
    }
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            int x1 = ch2n[arr[i][0][0]];
            int x2 = ch2n[arr[0][j][0]];
            int n0 = (x1+x2)%n;
            int n1 = (x1+x2)/n;
            if (strlen(arr[i][j])==2) {
                if (!(ch2n[arr[i][j][0]] == n1 && ch2n[arr[i][j][1]] == n0)) {
                    printf("ERROR!");
                    return 0;
                }
            } else {
                if (!(ch2n[arr[i][j][0]] == n0)) {
                    printf("ERROR!");
                    return 0;
                }
            }
        }
    }
    for (int i=0; i<n; ++i) {
        printf("%c=%d ", chpool[i], ch2n[chpool[i]]);
    }
    printf("\n%d", n);
    return 0;
}

