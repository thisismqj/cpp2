#include <bits/stdc++.h>
using namespace std;
int n, q;
int arr[1005];
void q_sort(int arr[],int pl, int pr) {
    if (pl>=pr) return;
    int pivot = arr[pl];
    int l=pl, r=pr;
    while (l<r) {
        while (arr[r]>=pivot&&r>l) --r;
        if (r==l) break;
        arr[l++] = arr[r];
        while (arr[l]<=pivot&&l<r) ++l;
        if (r==l) break;
        arr[r--] = arr[l];
    }
    arr[l] = pivot;
    q_sort(arr, pl, l-1);
    q_sort(arr, l+1, pr);
}
int main() {
    cin>>n>>q;
    for (int i=1; i<=n; ++i) {
        cin>>arr[i];
    }
    q_sort(arr, 1, n);
    for (int i=1; i<=q; ++i) {
        int in_x, useless;
        cin>>useless>>in_x;
        bool g_succ=false;
        for (int j=1; j<=n; ++j) {
            int x=in_x;
            int num = arr[j];
            bool succ=true;
            while (num!=0&&x!=0) {
                if (num%10!=x%10) {
                    succ=false;
                    break;
                }
                num/=10;x/=10;
            }
            if (x==0&&succ) {
                cout<<arr[j]<<endl;
                g_succ=true;
                break;
            }
        }
        if (!g_succ) cout<<"-1"<<endl;
    }
    return 0;
}
