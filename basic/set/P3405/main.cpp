#include <bits/stdc++.h>
using namespace std;
int c[475300];
int rc[475300];
inline int my_hash(string &s) {
    return (s[0]-'A')+26*(s[1]-'A')+26*26*(s[2]-'A')+26*26*26*(s[3]-'A');
}
void add_h(string &s1, string &s2) {
    string str1 = s1.substr(0, 2);
    string cs = str1+s2;
    string rcs = s2+str1;
    if (cs!=rcs) {
        ++c[my_hash(cs)];
        ++rc[my_hash(rcs)];
    }
}
int main() {
    unsigned long long ans=0;
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; ++i) {
        string s1, s2;
        cin >> s1 >> s2;
        add_h(s1, s2);
    }
    for (int i=0; i<475300; ++i) {
        if (c[i]&&rc[i]) {
            ans+=(c[i]*rc[i]);
        }
    }
    ans>>=1;
    printf("%llu", ans);
    return 0;
}
