#include <bits/stdc++.h>
using namespace std;
struct DLink {
    int pre, aft;
    int val;
    DLink(int _pre=0, int _aft=0, int _val=0):
        pre{_pre}, aft{_aft}, val{_val} {}
} Data[1005];
int p=1;
int find(int x) {
    int i=1;
    while (Data[i].val!=x && i) i = Data[i].aft;
    return i;
}
void insert_b(int x, int y) { // y插入x前
    int i=find(x);
    Data[++p] = DLink(Data[i].pre, i, y);
    Data[Data[i].pre].aft=p;
    Data[i].pre=p;
}
void insert_a(int x, int y) {// y插入x后
    int i=find(x);
    Data[++p] = DLink(i, Data[i].aft, y);
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
    Data[Data[i].pre].aft = Data[i].aft;
    Data[Data[i].aft].pre = Data[i].pre;
}
int main() {
    Data[1].val=1;
    return 0;
}
