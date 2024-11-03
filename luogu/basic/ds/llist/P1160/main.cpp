#include <bits/stdc++.h>
using namespace std;
struct DLink {
    int pre, aft;
    int val;
    DLink(int _pre=0, int _aft=0, int _val=0):
        pre{_pre}, aft{_aft}, val{_val} {}
} Data[200005];
int Dindex[200005];
int p=1;
int left_i;
inline int find(int x) {
    return Dindex[x];
}
void insert_b(int x, int y) { // y插入x前
    int i=find(x);
    Data[++p] = DLink(Data[i].pre, i, y);
    Dindex[y] = p;
    if (i==left_i) left_i = p;
    Data[Data[i].pre].aft=p;
    Data[i].pre=p;
}
void insert_a(int x, int y) {// y插入x后
    int i=find(x);
    Data[++p] = DLink(i, Data[i].aft, y);
    Dindex[y] = p;
    Data[Data[i].aft].pre = p;
    Data[i].aft = p;
}
int ask_b(int x) {
    int i=find(x);
    return Data[Data[i].pre].val;
}
int ask_a(int x) {
    int i=find(x);
    return Data[Data[i].aft].val;
}
void del(int x) {
    int i=find(x);
    if (i!=-1) {
        if (i==left_i) left_i = Data[i].aft;
        Data[Data[i].pre].aft = Data[i].aft;
        Data[Data[i].aft].pre = Data[i].pre;
    }
    Dindex[x]=-1;
}
int n, m;
int main() {
    Data[1].val=1;
    Dindex[1] = 1;
    left_i = 1;
    scanf("%d", &n);
    // p==0: insert kleft, p==1: insert krt
    for (int i=2; i<=n; ++i) {
        int k, p;
        scanf("%d%d", &k, &p);
        p ? insert_a(k, i):insert_b(k, i);
    }
    scanf("%d", &m);
    for (int i=1; i<=m; ++i) {
        int x;
        scanf("%d", &x);
        del(x);
    }
    // i 初始化为left_i, 直到D[i].aft==0结束
    int i=left_i;
    while (Data[i].aft) {
        printf("%d ", Data[i].val);
        i = Data[i].aft;
    }
    printf("%d", Data[i].val);
    return 0;
}
