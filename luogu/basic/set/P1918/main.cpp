#include <bits/stdc++.h>
using namespace std;
inline int my_hash(int x) {
    // 对瓶子数
    return x%10007;
}
// 原始瓶子数，顺序
vector<pair<int, int> > hash2bot[10007];
int main() {
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; ++i) {
        int bot;
        scanf("%d", &bot);
        int b_hash = my_hash(bot);
        hash2bot[b_hash].push_back({bot, i});
    }
    int m;
    scanf("%d", &m);
    for (int i=1; i<=m; ++i) {
        int bot;
        scanf("%d", &bot);
        int b_hash = my_hash(bot);
        bool suc = false;
        if (!hash2bot[b_hash].empty()) {
            for (auto j:hash2bot[b_hash]) {
                if (j.first == bot) {
                    printf("%d\n", j.second);
                    suc=true;
                    break;
                }
            }
        } else {printf("0\n"); continue;}
        if (!suc) {printf("0\n");}
    }
    return 0;
}
