#include <bits/stdc++.h>
using namespace std;
const int max_len = 100005;
int arr[max_len];
void _qsort(int l, int r) {
    if (r-l<=0) return;
    int check = arr[l];
    int i=l, j=r;
    while (i<j) {
        while (i<=j&&arr[i]<=check) {
            ++i;
        }
        while (arr[j]>check) {
            --j;
        }
        if (i<j)
            swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[j]);
    _qsort(l, j-1);
    _qsort(j+1, r);
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        int num;
        scanf("%d", &num);
        arr[i] = num;
    }
    sort(arr+0, arr+n);
    for (int j=0; j<n; ++j)
        printf("%d ", arr[j]);
}

