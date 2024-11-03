#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull str2int(const string &str) {
    ull h=0;
    for (int i=5; i>=0; --i) {
        h=(h*58+str[i]-'A');
    }
    return h;
}
string int2str(ull x) {
    string str;
    for (int i=1; i<=6; ++i) {
        str+=(x%58+'A');
        x/=58;
    }
    return str;
}
// 10007个元素，每个元素存储一个<名字int, nxt int>对。
struct StrHash {
    ull read(ull n) {
        int h = n%10007;
        for (auto &v:arr[h]) {
            if (v.first==n) {
                return v.second;
            }
        }
        return n;
    }
    ull modify(ull n, ull v) {
        int h = n%10007;
        for (auto &vec:arr[h]) {
            if (vec.first==n) {
                return vec.second = v;
            }
        }
        arr[h].push_back({n, v});
        return v;
    }
    vector<pair<ull, ull>> arr[10007];
} nxt;
ull query_father(ull name) {
    if (nxt.read(name)==name) return name;
    return (nxt.modify(name, query_father(nxt.read(name))));
}
void cmb(ull n1, ull n2) {
    nxt.modify(query_father(n2), query_father(n1));
}
int main() {
    ull father;
    while (true) {
        char op;
        string str;
        cin>>op;
        if (op=='$') break;
        cin>>str;
        if (op=='#') {
            father = str2int(str);
        } else if (op=='+') {
            cmb(father, str2int(str));
        } else {
            cout << str << ' ' << int2str(query_father(str2int(str))) << endl;
        }
    }
    return 0;
}
