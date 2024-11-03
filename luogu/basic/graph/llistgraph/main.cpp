#include <bits/stdc++.h>
using namespace std;
struct Node{int val, nxt;} mem[1005]; //最多1005条边
int _p=1;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    _p = n+1;
    for (int i=1; i<=m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);// x->y
        if (!mem[x].val) {
            mem[x] = {y, 0};
        } else {
            int j=x;
            while (mem[j].nxt!=0) j = mem[j].nxt;
            mem[j].nxt = _p;
            mem[_p++] = {y, 0};
        }
    }
    for (int i=1; i<=n; ++i) {
        int j = i;
        if (mem[j].val) {
            printf("%d: ", i);
            while (mem[j].nxt!=0) {
                printf("%d ", mem[j].val);
                j = mem[j].nxt;
            }
            printf("%d\n", mem[j].val);
        }
    }
    return 0;
}
