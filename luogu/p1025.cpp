#include <bits/stdc++.h>
using namespace std;
int cnt=0;
int n, k;
int sum=0;
int cur=1;
void dfs(int depth=1) {
    if (depth == k-1) {
        cnt += max(0, ((n-sum)>>1)-cur+1);
        return;
    }
    int prev_cur = cur;
    for (int i=cur; i<=(n-sum)/(k-depth+1); ++i) {
        sum+=i;
        cur=i;
        dfs(depth+1);
        sum-=i;
    } 
    cur=prev_cur;
}
int main() {
    scanf("%d%d", &n, &k);
    dfs();
    printf("%d", cnt);
    return 0;
}

