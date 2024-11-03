#include <bits/stdc++.h>
using namespace std;
namespace P {
int n;
int sorted_index[32770], sorted_rank[32770];
int arr[32770];
int p_arr=1;
int ans=0;
inline int ar(int x) {
    return arr[sorted_index[x]];
}
void swap(int m, int n) {
    int a = sorted_index[m];
    int b = sorted_index[n];
    std::swap(sorted_index[sorted_rank[m]], sorted_index[sorted_rank[n]]);
    std::swap(sorted_rank[a], sorted_rank[b]);
}
void sort(int l, int r) {
    int mid = l+(r-l)/2;
    int mid_num = ar(mid);
    int i=l, j=r;
    do {
        while (ar(i)<mid_num) ++i;
        while (ar(j)>mid_num) --j;
        if (i<=j) {
            swap(i, j);
            ++i; --j;
        }
    } while (i<=j);
    if (j>l)
        sort(l, j);
    if (i<r)
        sort(i, r);
}
}
int main() {
    scanf("%d", &P::n);
    for (int i=1; i<=P::n; ++i) {
        scanf("%d", &P::arr[P::p_arr++]);
    }
    for (int i=1; i<=P::n; ++i) {
        P::sorted_index[i] = i;
        P::sorted_rank[i] = i;
    }
    P::ans+=P::arr[1];
    P::sort(1, P::n);
    for (int i=2; i<=P::n; ++i) {
        int abs_1, abs_2;
        int j=P::sorted_rank[P::arr[i]];
        int k;
        for (k=j-1; k>=1&&P::sorted_index[k]>=i;--k);
        if (k==0) abs_1 = INT_MAX;
        else abs_1 = P::arr[i]-P::arr[P::sorted_index[k]];
        for (k=j+1; k<=P::n&&P::sorted_index[k]<=i;++k);
        if (k==P::n+1) abs_2 = INT_MAX;
        else abs_2 = -P::arr[i]+P::arr[P::sorted_index[k]];
        P::ans+=min(abs_1, abs_2);
    }
    printf("%d", P::ans);
}

