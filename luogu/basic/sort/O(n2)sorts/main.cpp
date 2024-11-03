#include <bits/stdc++.h>
using namespace std;
const int arr_len = 5;
int arr[arr_len];
void select_sort() {
    for (int i=0; i<=arr_len-2; ++i) {
        int min=2147483647, min_index;
        for (int j=i; j<=arr_len-1; ++j) {
            if (arr[j] < min) {
                min = arr[j];
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}
void bubble_sort() {
    for (int i=arr_len-1; i>=1; --i) {
        for (int j=0; j<=i-1; ++j) {
            if (arr[j]>arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}
void insert_sort() {
    for (int i=1; i<=arr_len-1; ++i) {
        int arr_i = arr[i], j;
        for (j=0; j<i&&arr[j]<=arr_i; ++j);
        for (int k=i-1; k>=j; --k)
            arr[k+1] = arr[k];
        arr[j]=arr_i;
    }
}
void (*sorts[3])() = {select_sort, bubble_sort, insert_sort};
int main() {
    for (int i=0; i<arr_len; ++i) cin>>arr[i];
    int sort;
    cin>>sort;
    sorts[sort]();
    for (int i=0; i<arr_len; ++i) {
        cout<<arr[i]<<' ';
    }
}

