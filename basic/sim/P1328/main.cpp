#include <bits/stdc++.h>
using namespace std;
int rule[5][5] = {
    {0, -1, 1, 1, -1},
    {1, 0, -1, 1, -1},
    {-1, 1, 0, -1, 1},
    {-1, -1, 1, 0, 1},
    {1, 1, -1, -1, 0}
};
int p_a[200], p_b[200];
int main() {
    int n, n_a, n_b, a_win=0, b_win=0;
    cin>>n>>n_a>>n_b;
    for (int i=0; i<n_a; ++i)
        cin>>p_a[i];
    for (int j=0; j<n_b; ++j)
        cin>>p_b[j];
    for (int i=0;i<n;++i) {
        int a_i=p_a[i%n_a], b_i=p_b[i%n_b];
        int res=rule[a_i][b_i];
        if (res==1) ++a_win;
        if (res==-1) ++b_win;
    }
    cout<<a_win<<" "<<b_win;
}

