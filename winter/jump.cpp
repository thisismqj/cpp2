#include <bits/stdc++.h>
using namespace std;
int n, m;
int posx, posy, dx, dy;
int main() {
    cin>>n>>m;
    for (int i=1; i<=n; ++i) {
        int x, y;
        cin>>x>>y;
        dx+=x;dy+=y;
    }
    for (int i=1; i<=m; ++i) {
        cin>>posx>>posy;
        cout<<posx+dx<<" "<<posy+dy<<endl;
    }
    
    return 0;
}
