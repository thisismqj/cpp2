#include <bits/stdc++.h>
using namespace std;
bool vis[5005];
int pre[5005][5005];
int cnt=0;
queue<int>Q;
int main() {
    int c;
    cin>>c;
    for (int i=1; i<=c; ++i) {
        int j;
        cin>>j;
        for (int k=1; k<=j; ++k) {
            int n;
            cin>>n;
            pre[i][++pre[i][0]] = n;
        }
    }
    Q.push(1);
    while (!Q.empty()) {
        int x=Q.front();Q.pop();
        if (!vis[x]) {
            vis[x] = true;
            ++cnt;
        }else continue;
        for (int i=1; i<=pre[x][0]; ++i) {
            Q.push(pre[x][i]);
        }
    }
    cout<<cnt;
    return 0;
}