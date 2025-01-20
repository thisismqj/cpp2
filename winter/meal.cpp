#include <bits/stdc++.h>
using namespace std;
int t, n;
int pre[105], nxt[105];
bool vis[105];
bool early[105], late[105];
int main() {
    cin>>t>>n;
    for (int i=1; i<=n; ++i) {
        cin>>pre[i];
        nxt[pre[i]] = i;
    }
    bool able=true;
    for (int i=1; i<=n; ++i) {
        if (!vis[i]) {
            vis[i]=true;
            int j=i;
            int lcnt=0, rcnt=0, len=0;
            early[i]=0;
            while (j=pre[j]) {
                vis[j]=true;
                ++lcnt;
                early[j] = -lcnt;
            }
            len+=lcnt;
            j=i;
            while (j=nxt[j]) {
                vis[j]=true;
                ++rcnt;
                early[j] = rcnt;
            }
            len+=rcnt;
            if (len>t) able=false;
            j=i;
            while (j=pre[j]) {
                early[j] += lcnt+1;
                late[j] =early[j]+t-len;
            }
            early[i] = lcnt+1;
            late[i] =early[i]+t-len;
            j=i;
            while (j=nxt[j]) {
                early[j] += lcnt+1;
                late[j] =early[j]+t-len;
            }
        } 
    }
    for (int i=1; i<=n; ++i)
        cout<<early[i]<<' ';
    cout<<endl;
    if (able)
        for (int i=1; i<=n; ++i)
            cout<<late[i]<<' ';
    return 0;
}
