#include <bits/stdc++.h>
using namespace std;
struct Node {
    char left, right;
} t[130];
int n;
void dfs(char rt) {
    if (rt!='*') {
        putchar(rt);
        dfs(t[rt].left);
        dfs(t[rt].right);
    }
}
int main() {
    scanf("%d", &n);
    getchar();
    char root;
    cin >> root >> t[root].left >> t[root].right;
    getchar();
    for (int p=2; p<=n; ++p) {
        char cur;
        cin >> cur >> t[cur].left >> t[cur].right;
        getchar();
    }
    dfs(root);
    return 0;
}
