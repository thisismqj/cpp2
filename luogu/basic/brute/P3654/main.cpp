#include <bits/stdc++.h>
using namespace std;
char ground[100][101];
int main() {
    int r, c, k;
    scanf("%d %d %d", &r, &c, &k);
    for (int i=0; i<r; ++i) {
        scanf("%s", ground[i]);
    }
    int result=0;
    for (int i=0; i<r; ++i) {
        int available = 0;
        for (int j=0; j<c; ++j) {
            if (ground[i][j]=='.') ++available;
            if (ground[i][j]=='#') available=0;
            if (available>=k) ++result;
        }
    }
    if (k!=1)
        for (int j=0; j<c; ++j) {
            int available = 0;
            for (int i=0; i<r; ++i) {
                if (ground[i][j]=='.') ++available;
                if (ground[i][j]=='#') available=0;
                if (available>=k) ++result;
            }
        }
    printf("%d", result);
}

