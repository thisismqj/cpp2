#include <bits/stdc++.h>
using namespace std;
int s2hash(string str) {
    int hash=0;
    for (int i=0; i<str.length(); ++i) {
        hash = (hash*137+str[i])%10007;
    }
    return hash;
}
vector<string> hash2str[10007];
int n;
int main() {
    scanf("%d", &n);
    string inp;
    int cnt=0;
    for (int i=1; i<=n; ++i) {
        cin>>inp;
        int h = s2hash(inp);
        bool checked=false;
        for (auto i:hash2str[h]) {
            if (i==inp) checked = true;
        }
        if (!checked) {
            ++cnt;
            hash2str[h].push_back(inp);
        }
        inp.clear();
    }
    printf("%d", cnt);
    return 0;
}
