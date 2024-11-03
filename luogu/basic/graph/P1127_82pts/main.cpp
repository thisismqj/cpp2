#include <bits/stdc++.h>
using namespace std;
int n;
string wd[1005];
vector<int> whead[26];
int st[1005];
int _sp=0;
bool vis[1005];
int _p=0;
bool dfs(char ch) {
    char it[30], _itp=0;
    memset(it, 0, sizeof(it));
    if (ch=='*') {
        for (int i=0; i<26; ++i) {
            if (!whead[i].empty()) {
                it[_itp++] = i+'a';
            }
        }
    } else {
        it[0] = ch;
    }
    int i=0;
    while (it[i]) {
        char c = it[i];
        for (int x:whead[c-'a']) {
            bool allvis = true;
            if (!vis[x]) {
                allvis=false;
                vis[x] = true;
                int l = wd[x].length();
                st[_sp++] = x;
                if (dfs(wd[x][l-1])) return true;
                --_sp;
                vis[x] = false;
            }
            if (allvis) {
                bool fill = true;
                for (int i=0; i<n; ++i) {
                    if (!vis[i]) fill = false;
                }
                if (fill) {
                    for (int i=0; i<=_sp-2; ++i) {
                        cout<<wd[st[i]]<<'.';
                    }
                    cout<<wd[st[_sp-1]];
                    return true;
                }
            }
        }
        ++i;
    }
    bool fill = true;
    for (int i=0; i<n; ++i) {
        if (!vis[i]) fill = false;
    }
    if (fill) {
        for (int i=0; i<=_sp-2; ++i) {
            cout<<wd[st[i]]<<'.';
        }
        cout<<wd[st[_sp-1]];
        return true;
    }
    return false;
}
int main() {
    scanf("%d", &n);
    for (int i=1;i<=n; ++i) {
        cin>>wd[_p++];
    }
    sort(wd, wd+n);
    for (int i=0; i<_p; ++i) {
        whead[wd[i][0]-'a'].push_back(i);
    }
    if (!dfs('*')) {
        printf("***");
    }
    return 0;
}
