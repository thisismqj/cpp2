#include <bits/stdc++.h>
using namespace std;
int x;
int main() {
    cin>>x;
    int p1=(x%2==0), p2=(x>4&&x<=12);
    if (p1&&p2) {
        cout<<"1"<<" ";
    } else {
        cout<<"0"<<" ";
    }
    if (p1||p2) {
        cout<<"1"<<" ";
    } else {
        cout<<"0"<<" ";
    }
    if (p1+p2==1) {
        cout<<"1"<<" ";
    } else {
        cout<<"0"<<" ";
    }
    if (p1+p2==0) {
        cout<<"1"<<endl;
    } else {
        cout<<"0"<<endl;
    }
    return 0;
}
