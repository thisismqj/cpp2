#include <bits/stdc++.h>
using namespace std;
struct NoP {
    int x1, x2;
} nop[100005];
struct HashArr {
    // 仅用于修改, 返回改后值
    int modify(int x, int v) {
        for (auto &i:arr[my_hash(x)]) {
            if (x==i.first) {
                return i.second = v;
            }
        }
        arr[my_hash(x)].push_back({x, v});
        return v;
    }
    // 读取用read
    // 下标需存在
    int read(int x) {
        for (auto i:arr[my_hash(x)]) {
            if (i.first==x) return i.second;
        }
        return x;
    }
    void clear() {
        for (int i=0; i<10007; ++i) {
            vector<pair<int, int>>().swap(arr[i]);
        }
    }
    inline int my_hash(int x) {return x%10007;}
    // data: ind, val
    vector<pair<int, int>> arr[10007];
} arr_nxt, *curArr;
int find_head(int x) {
    int nxt = curArr->read(x);
    if (x==nxt) {return x;}
    else return curArr->modify(nxt, find_head(nxt));
}
void cmb(int x1, int x2) {
    // 将x2头部改为x1头部
    int h1 = find_head(x1);
    int h2 = find_head(x2);
    curArr->modify(h2, h1);
}
inline bool same_set(int x1, int x2) {
    return find_head(x1)==find_head(x2);
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; ++i) {
        int m, n_p=0;
        curArr = &arr_nxt;
        scanf("%d", &m);
        for (int j=1; j<=m; ++j) {
            int x1, x2, op;
            scanf("%d%d%d", &x1, &x2, &op);
            if (op==0) {
                nop[n_p++] = {x1, x2};
            } else {
                // 将x2所在集合并入x1
                cmb(x1, x2);
            }
        }
        bool yes=true;
        for (int i=0; i<n_p; ++i) {
            if (same_set(nop[i].x1, nop[i].x2)) {
                printf("NO\n");
                yes=false;
                break;
            }
        }
        if (yes) {
            printf("YES\n");
        }
        arr_nxt.clear();
    }
    return 0;
}