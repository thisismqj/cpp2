#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int step[205];
int len[205];
queue<int> Q;
int main() {
    memset(step, -1, sizeof(step));
    scanf("%d%d%d", &n, &a, &b);
    for (int i=1; i<=n; ++i) {
        scanf("%d", &len[i]);
    }
    Q.push(a);
    step[a] = 0;
    while (!Q.empty()) {
        int f = Q.front();
        Q.pop();
        int f1=f-len[f], f2=f+len[f];
        if (f1>=1 && step[f1]==-1) {
            step[f1] = step[f] + 1;
            Q.push(f1);
        }
        if (f2<=n && step[f2]==-1) {
            step[f2] = step[f] + 1;
            Q.push(f2);
        }
    }
    printf("%d", step[b]);
    return 0;
}

