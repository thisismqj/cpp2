#include <bits/stdc++.h>
using namespace std;
int m, n, p; // 总数 说谎 证词
// 建立一个名字到索引的映射，可以名字到索引
string names[25];
int _np = 1;
int str2index(string &x) {
    // 确保x存在
    for (int i=1; i<=m; ++i) {
        if (x == names[i]) return i;
    }
    return -1;
}
int str2weekday(string &x) {
    // 确保x存在
    switch (x[0]) {
    case 'M':
        return 1;
    case 'T':
        if (x[1]=='u') return 2;
        else return 4;
    case 'W':
        return 3;
    case 'F':
        return 5;
    case 'S':
        if (x[1]=='a') return 6;
        else return 7;
    }
    return -1;
}
int find_set[25];// 并查集
bool enemies[21][21]; // 邻接矩阵 敌人无向图
vector<int> claim[25]; //claim[x]: 指控x的人
vector<int> not_claim[25]; //claim[x]: 指控x的人
vector<int> week_claim[8]; // 指认week的人
inline void make_enemy(int x, int y) {
    enemies[y][x] = enemies[x][y] = true;
}
int color[25]; // 集合到染色
bool self_guilt(string &x) {
    // 读名字
    int sender;
    int i=0;
    for (; x[i]!=':'; ++i);
    sender = str2index(x.substr(0, i));
    i+=2;
    int target_start = i;
    for (; x[i]!=' '; ++i);
    // special
    if (x[i+1]=='a'&&x[i+4]=='g') {
        claim[sender].push_back(sender);
        return true;
    }
    return false;
}
bool self_not_guilt(string &x) {
    // 读名字
    int sender;
    int i=0;
    for (; x[i]!=':'; ++i);
    sender = str2index(x.substr(0, i));
    i+=2;
    int target_start = i;
    for (; x[i]!=' '; ++i);
    // special
    if (x[i+1]=='a'&&x[i+4]=='n') {
        not_claim[sender].push_back(sender);
        return true;
    }
    return false;
}
bool other_guilt(string &x) {
    // 读名字
    int sender;
    int i=0;
    for (; x[i]!=':'; ++i);
    sender = str2index(x.substr(0, i));
    i+=2;
    int target_start = i;
    for (; x[i]!=' '; ++i);
    // special
    if (x[i+1]=='i'&&x[i+4]=='g') {
        int target = str2index(x.substr(target_start, i-target_start))
        return true;
    }
    return false;
}
bool other_not_guilt(string &x) {
    // 读名字
    int sender;
    int i=0;
    for (; x[i]!=':'; ++i);
    sender = str2index(x.substr(0, i));
    i+=2;
    int target_start = i;
    for (; x[i]!=' '; ++i);
    // special
    if (x[i+1]=='i'&&x[i+4]=='n') {
        int target = str2index(x.substr(target_start, i-target_start))
        return true;
    }
    return false;
}
bool weekday(string &x) {
    // 读名字
    int sender;
    int i=0;
    for (; x[i]!=':'; ++i);
    sender = str2index(x.substr(0, i));
    i+=2;
    int target_start = i;
    for (; x[i]!=' '; ++i);
    if (x.substr(target_start, i-target_start)=="Today") {
        // 仅用星期的前两个字母
        int week = str2weekday(x.substr(target_start+9, 2));
        week_claim[week].push_back(sender);
        return true;
    } else
        return false;
}
bool (*inp_handle[5]) (string &) = {self_guilt, self_not_guilt, other_guilt, other_not_guilt, weekday};
int main() {
    scanf("%d%d%d", &m, &n, &p);
    // 并查集初始化
    for (int i=1; i<=m; ++i) find_set[i] = i;
    for (int i=1; i<=m; ++i) {
        cin >> names[i];
    }
    for (int i=1; i<=p; ++i) {
        string st;
        getline(cin, st);
        for (int i=0; i<5; ++i) {
            if (inp_handle[i](st)) break;
        }
    }
    // 建立enemy图和邻接表

    // 录入完
    return 0;
}
