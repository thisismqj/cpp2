#include <bits/stdc++.h>
using namespace std;
int q;
// 链表
struct Node {
    int left, right;
    int val;
    int sz; // 以节点为根的子树大小
    int n;
    Node(int l, int r, int v, int s, int _n):
        left{l}, right{r}, val{v}, sz{s}, n{_n} {}
    Node()=default;
} tree[10005];
int p=2;
// 5
void insert(int x, int rt=1) {
    // x: 内容, rt: 根
    if (tree[rt].sz==0) {
        tree[rt].val = x;
        ++tree[rt].sz;
        ++tree[rt].n;
        return;
    }
    if (x<tree[rt].val) {
        if (tree[rt].left==0) tree[rt].left=p++;
        insert(x, tree[rt].left);
        ++tree[rt].sz;
    } else if (x>tree[rt].val) {
        if (tree[rt].right==0) tree[rt].right=p++;
        insert(x, tree[rt].right);
        ++tree[rt].sz;
    } else {
        ++tree[rt].n;
        ++tree[rt].sz;
    }
}
// 1
int e2rank(int x, int rt=1) {
    if (rt==0) return 1;
    if (x==tree[rt].val) {
        return tree[tree[rt].left].sz+tree[rt].n;
    } else if (x>tree[rt].val) {
        return tree[tree[rt].left].sz+e2rank(x, tree[rt].right)+tree[rt].n;
    } else {
        return e2rank(x, tree[rt].left);
    }
}
int e2rankl(int x, int rt=1) {
    if (rt==0) return 1;
    if (x==tree[rt].val) {
        return tree[tree[rt].left].sz+1;
    } else if (x>tree[rt].val) {
        return tree[tree[rt].left].sz+e2rankl(x, tree[rt].right)+tree[rt].n;
    } else {
        return e2rankl(x, tree[rt].left);
    }
}
// 2
int rank2e(int r, int rt=1) {
    if (r<=0) return -2147483647;
    if (r>p-1) return 2147483647;
    int lsz = tree[tree[rt].left].sz;
    if (r<=lsz) {
        return rank2e(r, tree[rt].left);
    } else if (lsz+1<=r&&r<=lsz+tree[rt].n) {
        return tree[rt].val;
    } else {
        return rank2e(r-lsz-tree[rt].n, tree[rt].right);
    }
}
// 3
int before(int x) {
    int rk = e2rankl(x);
    return rank2e(rk-1);
}
// 4
int after(int x) {
    int rk = e2rank(x);
    return rank2e(rk+1);
}
// end
int main() {
    scanf("%d", &q);
    for (int i=1; i<=q; ++i) {
        int op, num;
        scanf("%d%d", &op, &num);
        switch (op) {
        case 5:
            insert(num);
            break;
        case 1:
            printf("%d\n", e2rank(num));
            break;
        case 2:
            printf("%d\n", rank2e(num));
            break;
        case 3:
            printf("%d\n", before(num));
            break;
        case 4:
            printf("%d\n", after(num));
            break;
        }
    }
    return 0;
}
