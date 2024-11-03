#include <bits/stdc++.h>
using namespace std;
char mid[10], aft[10];
void dfs(int l1, int l2, int l) {
    char rt=aft[l2+l-1];
    putchar(rt);
    int i;
    for (i=l1; mid[i]!=rt; ++i);
    int len1 = i-l1;
    int len2 = l1+l-1-i;
    if (len1>0) dfs(l1, l2, len1);
    if (len2>0) dfs(i+1, l2+len1, len2);
}
int main() {
    cin>>mid>>aft;
    dfs(0, 0, strlen(mid));
    return 0;
}
