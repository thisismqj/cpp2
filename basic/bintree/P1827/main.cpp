#include <bits/stdc++.h>
using namespace std;
char s1[30], s2[30];
int len;
struct Node {
    char left, right;
} tree[100];
char dfs(int l1, int r1, int l2, int r2) {
// 重建树, 返回根节点
    char root = s2[l2];
    int i;
    for (i=l1; s1[i]!=root;++i) ;
    if (i>l1) tree[root].left = dfs(l1, i-1, l2+1, l2-l1+i);
    if (i<r1) tree[root].right = dfs(i+1, r1, -r1+r2+i+1, r2);
    return root;
}
void post_order(char root) {
    if (tree[root].left) post_order(tree[root].left);
    if (tree[root].right) post_order(tree[root].right);
    putchar(root);
}
int main() {
    scanf("%s", s1);
    scanf("%s", s2);
    len = strlen(s1);
    char root = dfs(0, len-1, 0, len-1);
    post_order(root);
    return 0;
}
