#include <bits/stdc++.h>
using namespace std;
const char *ans[2] = {"Local", "Luogu"};
int main() {
    int n;
    cin>>n;
    cout<<((3*n+11>5*n)?ans[0]:ans[1]);
    return 0;
}
