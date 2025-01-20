#include <bits/stdc++.h>
using namespace std;
const int modn=1000003;
bool discovered[modn] = {1};
int my_hash(const string &b) {
    int val = 0;
    for (int i=0; i<b.length(); ++i) {
        val = (val*75+b[i]-'0')%modn;
    }
    return val;
}
int n, m, k;
vector<string> dest;
int main() {
    cin>>n>>m>>k;
    dest.push_back("");
    for (int i=1; i<=n; ++i) {
        string x;
        cin>>x;
        dest.push_back(x);
    }
    for (int i=1; i<=m; ++i) {
        string x;
        cin>>x;
        discovered[my_hash(x)] = true;
    }
    for (int i=1; i<=k; ++i) {
        string x;
        cin>>x;
        dest.push_back(x);
    }
    sort(dest.begin(), dest.end());
    for (string &e: dest) {
        if (!discovered[my_hash(e)])
            cout<<e<<endl;
    }
    return 0;
}
