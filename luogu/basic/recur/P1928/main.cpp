#include <bits/stdc++.h>
using namespace std;
// expand函数： 或括号开始 到 结束 或括号结束的字符串。。。
string expand() {
    char c;
    string x, ret;// temp, return
    while (cin>>c) { // 未结束
        if (c=='[') {
            int n;
            scanf("%d", &n); // 读个数
            x=expand();
            while (n--) ret+=x;
            continue;;
        }
        if (c==']') return ret;
        ret+=c;
    }
    return ret;
}
int main() {
    printf("%s", expand().c_str());
}

