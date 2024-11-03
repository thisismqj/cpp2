#include <bits/stdc++.h>
using namespace std;
const int arr_len = 5;
int arr[arr_len];
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
void quick_sort() {
    _qsort(0, arr_len-1);
}
void (*sorts[])() = {quick_sort};
int main() {
    for (int i=0; i<arr_len; ++i) cin>>arr[i];
    int sort;
    cin>>sort;
    sorts[sort]();
    for (int i=0; i<arr_len; ++i) {
        cout<<arr[i]<<' ';
    }
}

