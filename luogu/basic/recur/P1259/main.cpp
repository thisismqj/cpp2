#include <bits/stdc++.h>
using namespace std;
char str[205];
void next_step(int n) {
    char src_str[2];
    if (n==0) return;
    // 挖坑，填坑
    int dst, src;
    //
    //
    src_str[0] = str[src];
    src_str[1] = str[src+1];
    for (int i=1; i<=dst; ++i) {
        putchar(str[i]);
    }
    printf("--");
    for (int i=dst+1; i<=n; ++i) {
        putchar(str[i]);
    }
    putchar('\n');
    // move
    
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i=1;i<=n;++i) str[i] = 'o';
    for (int i=n+1;i<=2*n;++i) str[i] = '*';
    next_step(n);
}

