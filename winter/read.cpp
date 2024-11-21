#include <bits/stdc++.h>
using namespace std;
int m, n;
int arr[1005];
int main() {
    cin>>m>>n;
    memset(arr, -1, sizeof(arr));
    int ptr=1, cnt=0;
    for (int i=1; i<=n; ++i) {
        int x;
        cin>>x;
        bool notfound=true;
        for (int j=1; j<=m; ++j) {
            if (x==arr[j]) {
                notfound=false;
                break;
            }
        }
        if (notfound) {
            ++cnt;
            arr[ptr++] = x;
            if (ptr==m+1) ptr=1;
        }
    }
    cout<<cnt;
    return 0;
}
