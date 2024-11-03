#include <bits/stdc++.h>
using namespace std;
char s1[10], s2[10];
int p=1;
struct Node {
    int left, right;
    int val;
} t[20];
int dfs(int l1, int l2, int len, int rt=1) {
    // 生成树:给出根节点位置，添加根节点和子树, 返回根节点索引
    int bitset1=0, bitset2=0;
    int i;
    for (i=len-1; i>=0; --i) {
        bitset1 |= 1<<(s1[l1+i]-'A');
        bitset2 |= 1<<(s2[l2+i]-'A');
        if (bitset1==bitset2) break;
    }
    t[p++].val = s2[l2+len-1];
    int _p = p-1;
    if (i>0)
        t[_p].left = dfs(l1, l2, l1+i-l1, p);
    if (len-i-1>0)
        t[_p].right = dfs(l1+i+1, l2+i, len-i-1, p);
    return _p;
}
void dfr(int rt) {
    putchar(t[rt].val);
    if (t[rt].left)
        dfr(t[rt].left);
    if (t[rt].right)
        dfr(t[rt].right);
}
int main() {
    scanf("%s", s1);
    scanf("%s", s2);
    dfs(0, 0, strlen(s1));
    dfr(1);
    return 0;
}