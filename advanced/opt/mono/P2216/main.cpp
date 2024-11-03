#include <bits/stdc++.h>
using namespace std;
// iter each square
// maintain the max & min
// record if ans > max-min
int tile_max[1005][1005], tile_min[1005][1005];
int brick_max, brick_min;
int arr[1005][1005];
int main() {
    int a, b, n;
    scanf("%d%d%d", &a, &b, &n);
    for (int i=1; i<=a; ++i)
        for (int j=1; j<=b; ++j)
            scanf("%d", &arr[i][j]);
    for (int j=1; j<=b; ++j) {
        deque<int> Q, Qm;
        for (int i=1; i<=a; ++i) {
            while (!Q.empty()&&Q.front()<=i-n) Q.pop_front();
            while (!Qm.empty()&&Qm.front()<=i-n) Qm.pop_front();
            int x = arr[i][j];
            while (!Q.empty()&&arr[Q.back()][j]<=x) Q.pop_back();
            while (!Qm.empty()&&arr[Qm.back()][j]>=x) Qm.pop_back();
            Q.push_back(i);
            Qm.push_back(i);
            if (i-n+1>0) {
                tile_max[i-n+1][j] = arr[Q.front()][j];
                tile_min[i-n+1][j] = arr[Qm.front()][j];
            }
        }
    }
    int min_d = INT_MAX;
    for (int i=1; i<=a-n+1; ++i) {
        deque<int> Q, Qm;
        for (int j=1; j<=b; ++j) {
            while (!Q.empty()&&Q.front()<=j-n) Q.pop_front();
            while (!Qm.empty()&&Qm.front()<=j-n) Qm.pop_front();
            int x = tile_max[i][j];
            int xm = tile_min[i][j];
            while (!Q.empty()&&tile_max[i][Q.back()]<=x) Q.pop_back();
            while (!Qm.empty()&&tile_min[i][Qm.back()]>=xm) Qm.pop_back();
            Q.push_back(j);
            Qm.push_back(j);
            if (j-n+1>0) {
                brick_max = tile_max[i][Q.front()];
                brick_min = tile_min[i][Qm.front()];
                min_d = min(min_d, brick_max-brick_min);
            }
        }
    }
    printf("%d", min_d);
    return 0;
}
