#include <bits/stdc++.h>
using namespace std;
struct P {
    int x, y, z;
} points[50005];
bool cmp(P& p1, P& p2) {
    return p1.z<p2.z;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        scanf("%d %d %d", &points[i].x, &points[i].y, &points[i].z);
    }
    sort(points, points+n, cmp);
    double distance=0.0f;
    for (int i=1; i<n; ++i) {
        distance += sqrt((points[i].x-points[i-1].x)*(points[i].x-points[i-1].x)+(points[i].y-points[i-1].y)*(points[i].y-points[i-1].y)+(points[i].z-points[i-1].z)*(points[i].z-points[i-1].z));
    }
    printf("%.3f", distance);
}

