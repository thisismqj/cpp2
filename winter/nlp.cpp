#include <bits/stdc++.h>
using namespace std;
const int modn=10007;
int dict[modn];
int my_hash(const string &b) {
    int val = 0;
    for (int i=0; i<b.length(); ++i) {
        val = (val*26+b[i]-'a')%modn;
    }
    return val;
}
int n, m;
char my_key[25];
int main() {
    cin>>n>>m;
    for (int i=1; i<=n; ++i) {
        string key; int val;
        cin>>key>>val;
        dict[my_hash(key)] = val;
    }
    int ch;
    while ((ch=getchar())!=EOF) {
        if (ch!='{') {
            putchar(ch);
        } else {
            int _p = 0;
            while ((my_key[_p++]=getchar())!='}') ;
            my_key[_p-1] = 0;
            cout<<dict[my_hash(my_key)];
        }
    }
    return 0;
}
