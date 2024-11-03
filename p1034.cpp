#include <bits/stdc++.h>
using namespace std;
int n, k;
struct Point {int x, y;} pts[55];
char p2r[55];
struct Rect {int x, y, w, h;} rects[5];
int ans = INT_MAX, cur_area;
// dfs每个点(需未加入: 0)
// 选择加入哪个矩形 (矩形无点则更新为点,
// 更新矩形包括的点 (已有其他矩形的点则回溯)
// 剪枝: 当前矩形面积>=ans则回溯
// 回溯:
//      点加入的矩形
//      矩形总面积
//      当前矩形数据
// 递归终点: num > n
bool p_in_rect(Point p, Rect r) {
    if (p.x>=r.x&&p.y>=r.y&&p.x<=r.x+r.h&&p.y<=r.y+r.w) return true;
    return false;
}
void dfs(int num) {
    char bak_p2r[55];
    if (num<=n && p2r[num]==0) {
        for (int i=1; i<=k; ++i) {
            if (rects[i].x == -1) {
                // 新矩形
                memcpy(bak_p2r, p2r, 55);
                p2r[num] = i;
                Rect bak = rects[i];
                rects[i].x = pts[num].x;
                rects[i].y = pts[num].y;
                rects[i].w=rects[i].h=0;
                // 回溯矩形, p2r
                dfs(num+1);
                rects[i] = bak;
                memcpy(p2r, bak_p2r, 55);
            } else {
                memcpy(bak_p2r, p2r, 55);
                p2r[num] = i;
                Rect bak = rects[i];
                int bak_cur_area = cur_area;
                rects[i].x = min(rects[i].x, pts[num].x);
                rects[i].y = min(rects[i].y, pts[num].y);
                rects[i].h += bak.x-rects[i].x;
                rects[i].w += bak.y-rects[i].y;
                rects[i].h = max(rects[i].h, pts[num].x-rects[i].x);
                rects[i].w = max(rects[i].w, pts[num].y-rects[i].y);
                cur_area += rects[i].w*rects[i].h-bak.w*bak.h;
                bool occ = false;
                // 查更新后是否包含其他矩形的点
                for (int j=1; j<=n; ++j) {
                    if (p_in_rect(pts[j], rects[i])) {
                        if (p2r[j]==0) p2r[j] = i;
                        else if (p2r[j]!=i) {
                            occ = true;
                            break;
                        }
                    }
                }
                if (occ||cur_area > ans) {
                    // 提前回溯
                    rects[i] = bak;
                    cur_area = bak_cur_area;
                    memcpy(p2r, bak_p2r, 55);
                } else {
                    dfs(num+1);
                    rects[i] = bak;
                    cur_area = bak_cur_area;
                    memcpy(p2r, bak_p2r, 55);
                }
            }
        }
    } else if (num > n) {
        // 结算
        if (cur_area < ans) {
            ans = cur_area;
        }
    } else dfs(num+1);
}
int main() {
    memset(rects, -1, sizeof(rects));
    scanf("%d%d", &n, &k);
    for (int i=1; i<=n; ++i) {
        scanf("%d%d", &pts[i].x, &pts[i].y);
    }
    dfs(1);
    printf("%d", ans);
    return 0;
}
