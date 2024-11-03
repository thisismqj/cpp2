#include <bits/stdc++.h>
using namespace std;
int p;
namespace P{
int p1, p2, p3;
int n;
int in[100005], st[100005], out[100005], dst[100005];
inline void iin() {
    // 入栈
    st[p2++] = in[p1++];
}
inline int iout() {
    out[p3++] = st[--p2];
    return st[p2];
}
inline void irin() {
    --p2;--p1;
}
inline void irout(int x) {
    --p3;st[p2++]=x;
}
bool dfs() { // return true 则成功找到
    if (p3==n) {
        for (int i=0; i<n; ++i) {
            if (out[i]!=dst[i]) return false;
        }
        return true;
    }
    // 若子函数true则return true
    if (p1!=n) {
        iin();
        if (dfs()) return true;
        irin();
    }
    if (p2!=0) {
        int x=iout();
        if (dfs()) return true;
        irout(x);
    }
    return false;
}
}
int main() {
    scanf("%d", &p);
    for (int i=1; i<=p; ++i) {
        scanf("%d", &P::n);
        P::p1=0;P::p2=0;P::p3=0;
        for (int j=0; j<P::n; ++j) {
            scanf("%d", &P::in[j]);
        }
        for (int j=0; j<P::n; ++j) {
            scanf("%d", &P::dst[j]);
        }
        if (P::dfs()) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
