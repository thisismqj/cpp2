#include <bits/stdc++.h>
using namespace std;
vector<int> arr[10007];
void clear() {
    for (int i=0; i<10007; ++i) 
        vector<int>().swap(arr[i]);
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; ++i) {
        clear();
        int m;
        scanf("%d", &m);
        for (int j=1; j<=m; ++j) {
            int x;
            scanf("%d", &x);
            bool find=false;
            for (int c:arr[((unsigned)x)%10007]) {
                if (c==x) {
                    find=true;
                    break;
                }
            }
            if (!find) {
                arr[((unsigned)x)%10007].push_back(x);
                printf("%d ", x);
            }
        }
        printf("\n");
    }
    return 0;
}
