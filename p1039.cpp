#include <bits/stdc++.h>
using namespace std;
int m, n, p; // 总数 说谎者 证言
map<string, int> name2num; // 名字到编号, 从1开始
struct Sentence {
    int sender, target;
} s[3][105];// s[0]: guilt ; s[1]: not guilt ; s[2]: week
int _gp = 0, _ngp = 0, _wp = 0;
char TF[25];
vector<int> result;
string num2name[25];
// 判断guilt 的指控
// guilt 自指, 则他说真话，否则说假话
// 其他人指guilt则真话，否则假话
// guilt自否则说假话，否人则说真话
// 其他人自否则说真话，否则说假话
// 有矛盾则退出
// 每一条证言，有发出者，接受者和类型
// 先处理guilt再处理day, 先处理说真话的人
// 如果某人说真话，则检查矛盾，将day设置为他的day
// 如果某人说假话，则放入队列尾, 直到处理完一轮
// 没矛盾则可能, 加名字
bool cmp(Sentence &s1, Sentence &s2) {
    return TF[s1.sender] > TF[s2.sender];
}
int main() {
    // 星期初始化
    name2num["Monday"] = 1;
    name2num["Tuesday"] = 2;
    name2num["Wednesday"] = 3;
    name2num["Thursday"] = 4;
    name2num["Friday"] = 5;
    name2num["Saturday"] = 6;
    name2num["Sunday"] = 7;
    cin>>m>>n>>p;
    for (int i=1; i<=m; ++i) {
        string name;
        cin>>name;
        name2num[name] = i;
        num2name[i] = name;
    }
    string stat;
    getline(cin, stat);
    for (int i=1; i<=p; ++i) {
        // cout<<"Reading Ln" << i << endl;
    // 处理证词
        getline(cin, stat);
        int j=0;
        while (stat[j]!=':') ++j;
        int sender = name2num[stat.substr(0, j)];
        int k = stat.find("I am guilty.");
        if (k!=-1) {
            s[0][_gp++] = {sender, sender};
            continue;
        }
        k = stat.find("I am not guilty.");
        if (k!=-1) {
            s[1][_ngp++] = {sender, sender};
            continue;
        }
        k = stat.find(" is guilty.");
        if (k!=-1) {
            int target = name2num[stat.substr(j+2, k-(j+2))];
            s[0][_gp++] = {sender, target};
            continue;
        }
        k = stat.find(" is not guilty.");
        if (k!=-1) {
            int target = name2num[stat.substr(j+2, k-(j+2))];
            s[1][_ngp++] = {sender, target};
            continue;
        }
        k = stat.find("Today is ");
        if (k!=-1) {
            int target = name2num[stat.substr(k+9, stat.size()-(k+9)-1)];
            s[2][_wp++] = {sender, target};
            continue;
        }
    }
    // 遍历每人可能是罪犯
    // 重置TF表为-1 (0: liar 1: honest)
    // 遍历guilt证词, 检查矛盾或设置TF表, 有矛盾则遍历下一个人是罪犯
    // 遍历not_guilt证词, 检查同上
    // 遍历week证词
    // 加result为罪犯名字
    for (int i=1; i<=m; ++i) {
        memset(TF, -1, sizeof(TF));
        bool con_flag = false;
        for (int j=0; j<_gp; ++j) {
            // s[0]
            bool honest=false;
            int t = s[0][j].target;
            if (t==i) honest = true;
            if (TF[s[0][j].sender] == -1) TF[s[0][j].sender] = honest;
            else if (TF[s[0][j].sender] != honest) {
                con_flag = true;
                break;
            }
        }
        if (con_flag) continue;
        for (int j=0; j<_ngp; ++j) {
            bool honest=false;
            int t = s[1][j].target;
            if (t!=i) honest = true;
            if (TF[s[1][j].sender] == -1) TF[s[1][j].sender] = honest;
            else if (TF[s[1][j].sender] != honest) {
                con_flag = true;
                break;
            }
        }
        bool week_success = false;
        if (con_flag) continue;
        int week = 0;
        sort(s[2], s[2]+_wp, cmp);
        if (_wp!=0&&TF[s[2][0].sender]==1) {
            week = s[2][0].target;
            for (int j=0; j<_wp; ++j) { // to end loop
                int sender = s[2][j].sender;
                int s_week = s[2][j].target;
                if (TF[sender]!=-1) {
                    if (TF[sender] == true) {
                        if (week==0) week = s_week;
                        else if (week!=s_week) {
                            con_flag = true;
                            break;
                        }
                    } else {
                        if (week!=0&&week==s_week) {
                            con_flag = true;
                            break;
                        }
                    }
                } else {
                    if (week!=0) {
                        if (week==s_week) TF[sender] = 1;
                        else TF[sender] = 0;
                    }
                }
            }
            if (con_flag) continue;
        } else if (_wp!=0) {
            for (week=1; week<=7; ++week) {
                for (int j=0; j<_wp; ++j) { // to end loop
                    int sender = s[2][j].sender;
                    int s_week = s[2][j].target;
                    if (s_week==week) {
                        if (TF[sender]==0) {
                            con_flag = true;
                            break;
                        } else TF[sender] = 1;
                    } else {
                        if (TF[sender]==1) {
                            con_flag = true;
                            break;
                        } else TF[sender] = 0;
                    }
                }
                if (con_flag) {con_flag = false; continue;}
                else {
                    week_success = true;
                    break;
                }
            }
            if (!week_success) continue;
        }
        // no con
        int always_lie_min = 0;
        for (int i=1; i<=m; ++i) if (TF[i]==0) ++always_lie_min;
        int always_lie_max = always_lie_min;
        for (int i=1; i<=m; ++i) if (TF[i]==-1) ++always_lie_max;
        if (always_lie_min<=n&&n<=always_lie_max) result.push_back(i);
    }
    if (result.size()==1) {
        cout<<num2name[result[0]];
    } else if (result.size()==0) {
        cout<<"Impossible";
    } else {
        cout<<"Cannot Determine";
    }
    // result.size()
    // ==1: 输出
    // >1: 多解
    // ==0: 无解
}
