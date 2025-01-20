#include <bits/stdc++.h>
using namespace std;
struct Rect {
    int x1, y1, x2, y2;
} hall, tmp;
int n;
int ans;
int int_s(Rect r1, Rect r2) {
    int x1 = max(r1.x1, r2.x1);
    int x2 = min(r1.x2, r2.x2);
    int y1 = max(r1.y1, r2.y1);
    int y2 = min(r1.y2, r2.y2);
    if (x1>=x2||y1>=y2) return 0;
    return (x2-x1)*(y2-y1);
}
int main() {
    cin>>n;
    cin>>hall.x2>>hall.y2;
    for (int i=1; i<=n; ++i) {
        cin>>tmp.x1>>tmp.y1>>tmp.x2>>tmp.y2;
        ans+=int_s(hall, tmp);
    }
    cout<<ans;
    return 0;
}
