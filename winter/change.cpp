#include <bits/stdc++.h>
using namespace std;
int n, m;
double sc[100005], rot[100005];
int main() {
    cin>>n>>m;
    for (int i=1; i<=n; ++i) {
        int op; double val;
        cin>>op>>val;
        if (op==1) sc[i] = val+sc[i-1]; else rot[i] = val+rot[i-1];
    }
    for (int i=1; i<=m; ++i) {
        double sc_v=0, rot_v=0;
        int l, r; double x, y;
        cin>>l>>r>>x>>y;
        sc_v = sc[r]-sc[l-1]; rot_v = rot[r]-rot[l-1];
        x*=sc_v, y*=sc_v;
        double xa = x*cos(rot_v)-y*sin(rot_v), ya = y*cos(rot_v)+x*sin(rot_v);
        printf("%.3lf %.3lf\n", xa, ya);
    }
    return 0;
}
