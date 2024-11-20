#include <bits/stdc++.h>
using namespace std;
int bucket_k[1005], bucket_l[1005];
int arr[1005];
int buf[1005];
bool cmp_k(int a, int b) {
    return bucket_k[a] > bucket_k[b];
}
bool cmp_l(int a, int b) {
    return bucket_l[a] > bucket_l[b];
}
int m, n, k, l, d;
int main() {
    cin>>m>>n>>k>>l>>d;
    while (d--) {
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        if (x1==x2) {
            // ||: l
            ++bucket_l[min(y1, y2)];
        } else {
            // =: k
            ++bucket_k[min(x1,x2)];
        }
    }
    for (int i=1; i<=m; ++i)
        arr[i] = i;
    sort(arr+1, arr+1+m, cmp_k);
    int _bufp = 0;
    for (int i=1; i<=k; ++i) buf[_bufp++] = arr[i];
    sort(buf, buf+k);
    for (int i=1; i<k; ++i)
        cout << buf[i-1] << ' ';
    cout <<buf[k-1];
    cout<<endl;
    for (int i=1; i<=n; ++i)
        arr[i] = i;
    sort(arr+1, arr+1+n, cmp_l);
    _bufp = 0;
    for (int i=1; i<=l; ++i) buf[_bufp++] = arr[i];
    sort(buf, buf+l);
    for (int i=1; i<l; ++i)
        cout << buf[i-1] << ' ';
    cout<<buf[l-1];
}