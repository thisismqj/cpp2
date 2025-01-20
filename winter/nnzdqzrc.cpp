#include <bits/stdc++.h>
using namespace std;
int arr[5][25];
bool cmp(int a, int b){return a>b;}
int ans=0;
int main() {
    for (int i=1; i<=4; ++i)
        cin>>arr[i][0];
    for (int i=1; i<=4; ++i){
        for (int j=1; j<=arr[i][0]; ++j)
            cin>>arr[i][j];
        sort(arr[i]+1, arr[i]+1+arr[i][0], cmp);
        int l=0, r=0, p=1;
        while (p<=arr[i][0]) {
            if (l<=r) {
                l+=arr[i][p++];
            } else {
                r+=arr[i][p++];
            }
        }
        ans+=max(l, r);
    }
    cout<<ans;
    return 0;
}