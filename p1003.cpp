#include <bits/stdc++.h>
using namespace std;
int n;
int x, y;
struct Sheet {
    int x, y, w, h;
} sheets[10005];
int cur_sheet=-1;
void update(int i) {
    if (sheets[i].x<=x&&sheets[i].y<=y
    &&x<=sheets[i].x+sheets[i].h-1
    &&y<=sheets[i].y+sheets[i].w-1) cur_sheet = i;
}
int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; ++i) {
        scanf("%d%d%d%d", &sheets[i].x, &sheets[i].y, &sheets[i].h, &sheets[i].w);
    }
    scanf("%d%d", &x, &y);
    for (int i=1; i<=n; ++i) {
        update(i);
    }
    printf("%d", cur_sheet);
    return 0;
}
