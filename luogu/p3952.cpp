#include <bits/stdc++.h>
using namespace std;
int k;
int exp_o, ln, ln_ptr, prg_o;
bool err = false;
bool vars[128];
// return o of ln p to ln q, -1 if err
int dfs(int dep, char clear_var) {
    cout<<"Recur starting with depth:"<<dep<<", clear_sym:"<<clear_var<<endl;
    string cur_ln;
    int o=-1, c;
    // return: read a line start with E or over ln cnt, --dep
    // if dep!=0 return -1
    // if redefined return -1
    char cur_sym;
    while (ln_ptr<=ln) {
        getline(cin, cur_ln);
        ++ln_ptr;
        if (cur_ln[0]=='E') {
            vars[clear_var] = false;
            --dep;
            break;
        } else {
            ++dep;
            // start with a F
            char sym=cur_ln[2];
            if (!vars[sym]) {vars[sym]=true; cur_sym = sym;}
            else return INT_MIN;
            // read p
            int _p = 4;
            string st_r, end_r;
            while (cur_ln[_p]!=' ') {
                st_r+=cur_ln[_p];
                ++_p;
            }
            ++_p;
            while (_p<cur_ln.length()) {
                end_r+=cur_ln[_p];
                ++_p;
            }
            if (st_r=="n") {
                if (end_r=="n") c=0;
                else c = -1;
            } else {
                if (end_r=="n") c=1;
                else if (atoi(end_r.c_str()) >= atoi(st_r.c_str())) c=0;
                else c=-1;
            } 
            cout<<"Init dfs, St:"<<st_r<<", End:"<<end_r<<", "<<"Lv:"<< c<<endl;
            int inner = dfs(1, sym); 
            if (inner==INT_MIN) return INT_MIN;
            if (c!=-1) {
                o = max(o, inner+c); 
            }
        }
    }
    if (dep==0) return o;
    else return INT_MIN;
}
int main() {
    cin>>k;
    for (int i=1; i<=k; ++i) {
        cin>>ln;
        string o_exp;
        cin>>o_exp;
        if (o_exp[2]=='1') {
            exp_o = 0;
        } else {
            exp_o = 0;
            for (int i=4; o_exp[i]!=')'; ++i) {
                exp_o = exp_o*10+o_exp[i]-'0';
            }
        }
        ln_ptr=1;
        int ans = dfs(0, 0);
        if (ans=-1) ans=0;
        if (ans==INT_MIN) {
            cout<<"ERR"<<endl;
        } else if (ans==exp_o) {
            cout<<"Yes"<<endl;
        } else cout<<"No"<<endl;
    } 
    return 0;
}


