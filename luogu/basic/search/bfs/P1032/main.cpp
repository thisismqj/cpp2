#include <bits/stdc++.h>
using namespace std;
vector<int> match(const string &s, const string &p) {
    // don't match return -1;
    // check first character, if match then continue
    // i: index of s 
    // xxxxxxxxx
    //       yyy
    if (s.length()<p.length()) return {};
    vector<int> result;
    for (int i=0; i <= s.length()-p.length(); ++i) {
        if (s[i] == p[0]) {
            bool m = true;
            for (int j=0; j<p.length(); ++j) {
                if (s[i+j]!=p[j]) {
                    m = false;
                    break;
                }
            }
            if (m) result.push_back(i);
        }
    }
    return result;
}
queue<pair<string, int>> Q;
string a, b;
string rules[7][2];
int main() {
    cin >> a >> b;
    int i=1;
    while (cin>>rules[i][0]>>rules[i][1]) {
        // printf("%d", i);
        ++i;
    }
    // printf("OK\n");
    Q.push({a, 0});
    int steps;
    while (!Q.empty()) {
        pair<string, int> aa = Q.front();
        if (aa.second > 10) {
            steps = -1;
            break;
        }
        if (aa.first == b) {
            steps = aa.second;
            break;
        }
        Q.pop();
        for (int j=1; j<i; ++j) {
            vector<int> v = match(aa.first, rules[j][0]);
            for (int k=0; k<v.size(); ++k) {
                string aaa = aa.first;
                aaa.replace(v[k], rules[j][0].length(), rules[j][1]);
                Q.push({aaa, aa.second+1});
            }
        }
    }
    if (steps == -1)
        printf("NO ANSWER!");
    else
        printf("%d", steps);
    return 0;
}

