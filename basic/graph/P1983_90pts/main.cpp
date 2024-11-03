#include <bits/stdc++.h>
using namespace std;
set<int> edges[1005];
int ind[1005], iind[1005];
bool stop[1005];
vector<int> zeros;
int fread() {
    int r = 0;
    char ch=getchar();
    while ('0'<=ch&&ch<='9') {
        r = r*10 + ch-'0';
        ch = getchar();
    }
    return r;
}
int main() {
    int n, m;// 站，班次
    scanf("%d%d", &n, &m);
    getchar();
    for (int i=1; i<=m; ++i) {
        memset(stop, 0, sizeof(stop));
        int sc=fread();
        vector<int> v_stop;
        int f=0,l;
        for (int j=1; j<=sc; ++j) {
            int x=fread();
            if (!f) f=x;
            l=x;
            stop[x] = true;
            v_stop.push_back(x);
        }
        for (int j=f; j<=l; ++j) {
            if (!stop[j]) {
                for (int e:v_stop) {
                    ind[e]+=edges[j].insert(e).second;
                }
            }
        }
    }
    int max_ans=0;
    queue<pair<int, int>> Q;
    for (int i=1; i<=n; ++i) {
        if (ind[i]==0) 
            Q.push({i, 1});
    }
    while (!Q.empty()) {
        int x=Q.front().first, dep=Q.front().second; Q.pop();
        if (edges[x].size() == 0) max_ans=max(max_ans, dep);
        for (int e:edges[x]) {
            --ind[e];
            if (ind[e]==0) {
                Q.push({e, dep+1});
            }
        }
    }
    printf("%d", max_ans);
}
