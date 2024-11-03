#include <bits/stdc++.h>
using namespace std;
char screen[1030][2055];
void tri(int x, int y, int size) {
    if (size==1) {
        screen[x][y]='/';
        screen[x][y+1]='\\';
        screen[x+1][y-1]='/';
        screen[x+1][y]='_';
        screen[x+1][y+1]='_';
        screen[x+1][y+2]='\\';
    } else {
        --size;
        tri(x, y, size);
        tri(x+(1<<size), y-(1<<size), size);
        tri(x+(1<<size), y+(1<<size), size);
    }
}
int main() {
    memset(screen, ' ', sizeof(screen));
    int n;
    scanf("%d", &n);
    tri(1, 1<<n, n);
    for (int i=1;i<=1<<n;++i) {
        for (int j=1;j<=1<<(n+1);++j)
            putchar(screen[i][j]);
        putchar('\n');
    }
}

