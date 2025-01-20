#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int n, m;
int l_b(int x) {
    int l=1, r=n+1;
    while (l<r) {
        int mid=l+(r-l)/2;
        if (arr[mid]>=x) r = mid;
        else l = mid+1;
    }
    return l;
}
int main() {
    cin>>n>>m;
    for (int i=1; i<=n; ++i) {
        cin>>arr[i];
    }
    sort(arr+1, arr+1+n);
    for (int i=1; i<=m; ++i) {
        int op;
        cin>>op;
        switch(op) {
            int x, y, l, r;
        case 1:
            cin>>x;
            l = l_b(x);
            r = l_b(x+1);
            cout<<r-l<<endl;
            break;
        case 2:
            cin>>x>>y;
            l = l_b(x);
            r = l_b(y+1);
            cout<<max(r-l, 0)<<endl;
            break;
        case 3:
            cin>>x>>y;
            l = l_b(x);
            r = l_b(y);
            cout<<max(r-l, 0)<<endl;
            break;
        case 4:
            cin>>x>>y;
            l = l_b(x+1);
            r = l_b(y+1);
            cout<<max(r-l, 0)<<endl;
            break;
        case 5:
            cin>>x>>y;
            l = l_b(x+1);
            r = l_b(y);
            cout<<max(r-l, 0)<<endl;
            break;
        }
    }
    return 0;
}