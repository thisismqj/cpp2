#include <bits/stdc++.h>
using namespace std;
int n;
char st[105];
char cct[100];
int p=0;
int main() {
    cct['('] = ')';
    cct['['] = ']';
    scanf("%d", &n);
    getchar();
    for (int i=1; i<=n; ++i) {
        p=0;
        char ch;
        bool match = true;
        while ((ch = getchar())!='\n') {
            if (ch=='('||ch=='[') {
                st[p++] = ch;
            } else if (ch == ')'||ch==']') {
                --p;
                if (p<0||cct[st[p]]!=ch) {
                    match = false;
                    while (ch=getchar()!='\n');
                    break;
                } 
            }
        }
        if (match&&p==0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}

