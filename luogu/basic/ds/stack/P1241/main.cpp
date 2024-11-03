#include <bits/stdc++.h>
using namespace std;
string s, result;
int len;
struct Chp{char ch;int p;} st[105];
bool vis[105];
bool m[105];
int p=0;
int main() {
    cin>>s;
    len = s.length();
    for (int i=0; i<len; ++i) {
        char ch = s[i];
        if (ch=='(' || ch=='[') {
            st[p++] = {ch, i};
        } else {
            if (p>0) {
                char cch = st[--p].ch;
                int pp = st[p].p;
                if ((s[i]==']'&&cch=='[')||
                (s[i]==')'&&cch=='(')) {
                    vis[pp]=true;vis[i]=true;
                    m[pp]=true;m[i]=true;
                } else {
                    vis[i]=true;m[i]=false;
                    ++p;
                }
            } else {
                vis[i]=true;
                m[i]=false;
                ++p;
            }
        }
    }
    for (int i=0; i<len; ++i) {
        if (!vis[i]||!m[i]) {
            switch(s[i]) {
            case '(':
            case ')':
                result.push_back('(');
                result.push_back(')');
                break;
            case '[':
            case ']':
                result.push_back('[');
                result.push_back(']');
                break;
            }
        } else {
            result.push_back(s[i]);
        }
    }
    cout << result;
    return 0;
}
