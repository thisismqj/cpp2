#include <bits/stdc++.h>
using namespace std;
int n, m, end_t[25];
bool t_line[25][1005];// n: gongjian m: gongxu
int cur_ord[25]; // gongjian dangqiangongxu
int seq[405];// anpai sequence
int mach[25][25];// gongjian gongxu
int tme[25][25]; // gongjian gongxu
int main() {
    cin >>m>>n;
    for (int i=1; i<=m*n; ++i)
        cin>>seq[i];
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            cin>>mach[i][j];
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            cin>>tme[i][j];
    for (int i=1; i<=m*n; ++i) {
        ++cur_ord[seq[i]];
        int sp = 0;
        for (int j=end_t[seq[i]]+1; ;++j) {
            if (t_line[mach[seq[i]][cur_ord[seq[i]]]][j]==0) {
                ++sp;
                if (sp>=tme[seq[i]][cur_ord[seq[i]]]) {
                    for (int k=j; sp>0; --k,--sp) {
                        t_line[mach[seq[i]][cur_ord[seq[i]]]][k] = 1;
                        end_t[seq[i]] = j;
                    }
                    break;
                }
            } else {
                sp=0;
            }
        }
    }
    int ans=0;
    for (int i=1; i<=n; ++i)
        ans = max(ans, end_t[i]);
    cout<<ans;
}
