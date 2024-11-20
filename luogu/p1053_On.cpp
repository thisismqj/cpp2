#include <bits/stdc++.h>
using namespace std;
int e1[50005], e2[50005], arr[50005], nxt[50005], pre[50005], bucket[50005];
bool vis[50005];
int n;
int main() {
    cin>>n;
    for (int i=1; i<=n; ++i) arr[i] = i;
    // connect the edge
    // A->B requires B has a free edge
    for (int i=1; i<=n; ++i) {
        int d1, d2;
        cin>>d1>>d2;
        // d1 is free
        if (e1[d1]==0||e1[d1]==i) {
            // connect
            e1[d1] = i;
            e1[i] = d1;
        } else if (e2[d1]==0||e2[d1]==i) {
            e2[d1] = i;
            e1[i] = d1;
        } else {
            puts("-1"); return 0;
        }
        if (e1[d2]==0||e1[d2]==i) {
            // connect
            e1[d2] = i;
            e2[i] = d2;
        } else if (e2[d2]==0||e2[d2]==i) {
            e2[d2] = i;
            e2[i] = d2;
        } else {
            puts("-1"); return 0;
        }
    } 
    // iter
    // first choose e1/e2
    // record self, jump, check my e1/e2, choose the ineq one
    // clockwise, iter and update the ans
    // precalc the nxt[] and pre[]
    // from 1, nxt is e1, pre is e2
    int c_ptr = e1[1];vis[1] = true;nxt[1]=c_ptr;
    do {
        vis[c_ptr]=true;
        if (!vis[e2[c_ptr]]) {
            nxt[c_ptr] = e2[c_ptr];
        } else if (!vis[e1[c_ptr]]){
            nxt[c_ptr] = e1[c_ptr];
        } else {
            nxt[c_ptr] = 1;
            break;
        }
        c_ptr = nxt[c_ptr];
    } while (true);
    memset(vis, 0, sizeof(vis));
    c_ptr = e2[1]; vis[1]=true; pre[1] = c_ptr;
    do {
        vis[c_ptr]=true;
        if (!vis[e2[c_ptr]]) {
            pre[c_ptr] = e2[c_ptr];
        } else if (!vis[e1[c_ptr]]){
            pre[c_ptr] = e1[c_ptr];
        } else {
            pre[c_ptr] = 1;
            break;
        }
        c_ptr = pre[c_ptr];
    } while (true);
    int ans = INT_MAX;
    int v=1, p=1;
    do {
        int off = (v+n-p)%n;
        ++bucket[off];
        ++p;
        v=nxt[v];
    } while (v!=1);
    for (int i=0; i<n; ++i) {
        ans = min(ans, n-bucket[i]);
    }
    memset(bucket, 0, sizeof(bucket));
    p=1;
    do {
        int off = (v+n-p)%n;
        ++bucket[off];
        ++p;
        v=pre[v];
    } while (v!=1);
    for (int i=0; i<n; ++i) {
        ans = min(ans, n-bucket[i]);
    }
    cout<<ans;
}
