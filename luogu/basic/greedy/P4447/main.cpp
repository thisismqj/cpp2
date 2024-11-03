#include <bits/stdc++.h>
using namespace std;
int n;
struct Group {
    int len;
    int tail;
} g[100005];
int input[100005];
int g_len=0;
void inc(int index) {
    // 组尾追加，并排序
    ++g[index].len;++g[index].tail;
}
void create(int num) {
    ++g_len;
    g[g_len].len=1;
    g[g_len].tail=num;
}
int main() {
    scanf("%d", &n);
    for (int i=1;i<=n;++i)
        scanf("%d", &input[i]);
    sort(input+1, input+1+n);
    for (int i=1;i<=n;++i) {
        int ab=input[i];
        bool inc_flag = false;
        for (int i=g_len;i>=1;--i) {
            if (ab==g[i].tail+1) {
                inc(i);
                inc_flag=true;
                break;
            }
        }
        if (!inc_flag) {
            create(ab);
        }
    }
    int min=INT_MAX;
    for (int i=1;i<=g_len;++i) {
        if (min > g[i].len) min = g[i].len;
    }
    printf("%d", min);
}

