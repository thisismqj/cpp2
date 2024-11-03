#include <bits/stdc++.h>
using namespace std;
int l, n;
bool arr[5005];
int main() {
    scanf("%d%d", &l, &n);
    if (n==0) {
        printf("0 0");
        return 0;
    }
    for (int i=1; i<=n; ++i) {
        int x;
        scanf("%d", &x);
        arr[x] = true;
    }
    for (int p=(l+1)/2, q=(l+2)/2; p>=1&&q<=l; --p, ++q) {
        if (arr[p]) {
            printf("%d ", p);
            break;
        } else if (arr[q]) {
            printf("%d ", l+1-q);
            break;
        }
    }
    for (int p=1, q=l; p<=q; ++p, --q) {
        if (arr[p]) {
            printf("%d", l+1-p);
            break;
        } else if (arr[q]) {
            printf("%d", q);
            break;
        }
    }
    return 0;
}

