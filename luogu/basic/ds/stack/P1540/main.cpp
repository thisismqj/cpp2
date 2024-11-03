#include <bits/stdc++.h>
using namespace std;
int windex[1005];
int que[3005];
int head=1, tail=1;
int cnt=0, ccnt=0;
int m, n;
int pop() {
    --cnt;
    windex[que[head]] = 0;
    return que[head++];
}
void push(int x) {
    ++cnt;
    windex[x] = tail;
    que[tail++]=x;
}
int main() {
    scanf("%d%d", &m, &n);
    for (int i=1; i<=n; ++i) {
        int num;
        scanf("%d", &num);
        if (!windex[num]) {
            // 未存在
            if (cnt < m) {
                push(num);
            } else {
                pop();
                push(num);
            }
            ++ccnt;
        }
    }
    printf("%d", ccnt);
    return 0;
}
