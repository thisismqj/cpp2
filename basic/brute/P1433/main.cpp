#include <bits/stdc++.h>
using namespace std;
float pos[15][2];
int p[15];
int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; ++i) p[i] = i;
    for (int i=0; i<n; ++i)
        scanf("%f%f", &pos[i][0], &pos[i][1]);
    float min_dis=8000.f;
    do {
        float dis=0.f, dx, dy;
        dx = pos[p[0]][0];
        dy = pos[p[0]][1];
        dis+=sqrt(dx*dx+dy*dy);
        for (int i=1; i<n; ++i) {
            dx = pos[p[i]][0]-pos[p[i-1]][0];
            dy = pos[p[i]][1]-pos[p[i-1]][1];
            dis+=sqrt(dx*dx+dy*dy);
        }
        if (dis<min_dis) min_dis = dis;
    } while (next_permutation(p, p+n));
    printf("%.2f", min_dis);
}

