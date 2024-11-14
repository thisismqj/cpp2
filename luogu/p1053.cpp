// version 1 O(n^2)
#include <bits/stdc++.h>
using namespace std;
int pre[50005], nxt[50005], arr[50005], n;
int main() {
    cin>>n;
    for (int i=1; i<=n; ++i) arr[i]=i;
    for (int i=1; i<=n; ++i) {
        int p, n2;
        cin>>p>>n2;
        // 优先级有问题
        if (pre[p]==0||pre[p]==i) {
            // p:pre -> i
            // i:nxt -> p
            // i p
            pre[p] = i;
            nxt[i] = p;
        } else if (nxt[p]==0||nxt[p]==i) {
            // p:nxt -> i
            // i:pre -> p
            // p i
            nxt[p] = i;
            pre[i] = p;
        } else {
            // fail
            puts("-1");
            return 0;
        }
        if ((pre[n2]==0||pre[n2]==i)&&(nxt[i]==0||nxt[i]==n2)) {
            // n2:pre -> i
            // i:nxt -> n2
            // i n2
            pre[n2] = i;
            nxt[i] = n2;
        } else if ((nxt[n2]==0||nxt[n2]==i)&&(pre[i]==0||pre[i]==n2)) {
            // n2:nxt -> i
            // i:nxt -> n2
            // n2 i
            nxt[n2] = i;
            pre[i] = n2;
        } else {
            // fail
            puts("-1");
            return 0;
        }
    }
    // 比对不同个数, 尽量少
    int minn = INT_MAX;
    // 顺序
    for (int i=1; i<=n; ++i) {
        int cnt=0, ptr=i, ori=1; // ori: 原始环元素
        // i 为目标环的首元素
        do {
            if (ori!=ptr) ++cnt;
            ++ori;
        } while ((ptr=nxt[ptr])!=i);
        minn = min(minn, cnt);
    }
    // 逆序
    for (int i=1; i<=n; ++i) {
        int cnt=0, ptr=i, ori=1; // ori: 原始环元素
        // i 为目标环的首元素
        do {
            if (ori!=ptr) ++cnt;
            ++ori;
        } while ((ptr=pre[ptr])!=i);
        minn = min(minn, cnt);
    }
    cout<<minn;
}