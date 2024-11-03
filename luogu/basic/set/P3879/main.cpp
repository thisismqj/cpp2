#include <bits/stdc++.h>
using namespace std;
vector<pair<string, vector<int>>> arr[10007];
string readwd() {
    string str;
    char ch;
    while (true) {
        ch=getchar();
        if ('a'<=ch&&ch<='z') {
            str+=ch;
        } else {
            break;
        }
    }
    cout << "Read:" << str <<endl;
    return str;
}
int str_hash(string &str) {
    int h=0;
    for (int i=0; i<str.length(); ++i) {
        h=(h*26+str[i])%10007;
    }
    return h;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; ++i) {
        int l;
        scanf("%d ", &l);
        bool checked_wd_hash[10007];
        for (int j=1; j<=l; ++j) {
            string wd=readwd();
            int h = str_hash(wd);
            bool checked = checked_wd_hash[h];
            if (!checked) {
                bool find=false;
                for (auto &p: arr[h]) {
                    if (p.first==wd) {
                        p.second.push_back(i);
                        find=true;
                    }
                }
                if (!find) {
                    arr[h].push_back({wd, {i}});
                }
                checked_wd_hash[h] = true;
            }
        }
    }
    int m;
    scanf("%d\n", &m);
    for (int i=1; i<=m; ++i) {
        string wd=readwd();
        int h = str_hash(wd);
        for (auto &p: arr[h]) {
            if (p.first==wd) {
                for (auto &i: p.second) {
                    printf("%d ", i);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
