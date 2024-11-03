#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[105];
int main() {
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; ++i)
        arr[i] = i;
    int cnt=0, cnt2=0;
    while (true) {
        for (int i=1;i<=n;++i) {
            if (arr[i]!=-1) {
                ++cnt;
            } else continue;
            if (cnt%m==0) {
                printf("%d ", arr[i]);
                arr[i] = -1;
                ++cnt2;
            }
        }

        if (cnt2>=n) break;
    }
    return 0;
}
