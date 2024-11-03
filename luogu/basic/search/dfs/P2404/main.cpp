#include <bits/stdc++.h>
using namespace std;
int target;
char result[20];
int cur=0;
void dfs(int start, int sum) {
    int ccur = cur;
    for (int i=start; i<=sum/2; ++i) {
        cur+=sprintf(result+cur, "%d+", i);
        dfs(i, sum-i);
        cur = ccur;
    }
    if (sum!=target) {
        sprintf(result+cur, "%d", sum);
        printf("%s\n", result);
    }
}
int main() {
    scanf("%d", &target);
    dfs(1, target);
    return 0;
}

