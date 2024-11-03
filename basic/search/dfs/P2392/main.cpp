#include <bits/stdc++.h>
using namespace std;
int s[4], cur_s;
int arr[4][21], *cur_arr;
int t;
int cur_total_t, cur_sum, cur_min;
// 选择题目的一个子集
// 使得子集小于等于半数总时长
// 且子集和尽量大
// 时间为总时长-子集时长
// 用bin表示子集
// x表示第几个题目, cur_sum > 半数则比较
void dfs(int x) {
    if (2*cur_sum >= cur_total_t) {
        if (cur_min > cur_sum)
            cur_min = cur_sum;
        return;
    }
    if (x > cur_s) return ;
    // 不置
    dfs(x+1);
    cur_sum += cur_arr[x];
    dfs(x+1);
    cur_sum -= cur_arr[x];
}
int main() {
    scanf("%d%d%d%d", &s[0], &s[1], &s[2], &s[3]);
    for (int i=0; i<4; ++i) {
        for (int j=1; j<=s[i]; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i=0; i<4; ++i) {
        cur_s = s[i];
        cur_arr = arr[i];
        cur_total_t = 0;
        cur_sum = 0;
        cur_min = 2147483647;
        for (int j=1; j<=cur_s; ++j) {
            cur_total_t += cur_arr[j];
        }
        dfs(1);
        t += cur_min;
    }
    printf("%d", t);
    return 0;
}

