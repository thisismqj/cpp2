#include <bits/stdc++.h>
using namespace std;
int n;
bool col[14];
bool dia1[26], dia2[26];
int pos[14];
int cnt = 0;

void dfs(int x) {// x 从 1 到 n, 第x行
    if (x > n) {
        ++cnt;
        if (cnt <=3) {
            // 打印状态
            for (int i=1; i<=n; ++i) {
                printf("%d ", pos[i]);
            }
            putchar('\n');
        }
        return;
    }
    // 获取行, 列
    for (int i=1; i<=n; ++i) {
        // row = x, col = i
        int d1 = i - x + n;
        int d2 = i + x - 1;
        if (!col[i] && !dia1[d1] && !dia2[d2]) {
            pos[x] = i;
            col[i] = true;
            dia1[d1] = true;dia2[d2] = true;
            dfs(x+1);
            col[i] = false;
            dia1[d1] = false;dia2[d2] = false;
        }
    }
}
int main() {
    scanf("%d", &n);
    dfs(1);
    printf("%d", cnt);
    return 0;
}

