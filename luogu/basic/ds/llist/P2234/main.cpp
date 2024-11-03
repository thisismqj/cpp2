#include <bits/stdc++.h>
using namespace std;
int p[32770], q[32770];
void m_swap(int m, int n) {
    swap(p[m], p[n]);
}
int arr[32770];
void m_sort(int l, int r) {
    int mid = l+(r-l)/2;
    int mid_num = arr[p[mid]];
    int i=l, j=r;
    do {
        while (arr[p[i]]<mid_num) ++i;
        while (arr[p[j]]>mid_num) --j;
        if (i<=j) {
            m_swap(i, j);
            ++i; --j;
        }
    } while (i<=j);
    if (j>l)
        m_sort(l, j);
    if (i<r)
        m_sort(i, r);
}
int n;
int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; ++i) {
        scanf("%d", &arr[i]);
    }
    for (int i=1; i<=n; ++i) {
        p[i] = i;
    }
    int ans=0;
    ans+=arr[1];
    m_sort(1, n);
    for (int i=n; i>=1; --i) {
        q[p[i]] = i;
    }
    for (int i=2;i<=n;++i) {
        int a1, a2;
        int j=q[i];
        int k;
        for (k=j-1;k>=1&&p[k]>=i;--k);
        if (k==0) a1 = INT_MAX;
        else a1 = arr[i] - arr[p[k]];
        for (k=j+1;k<=n&&p[k]>=i;++k);
        if (k==n+1) a2 = INT_MAX;
        else a2=arr[p[k]] - arr[i];
        ans+=min(a1, a2);
    }
    printf("%d", ans);
}

