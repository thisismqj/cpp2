#include <bits/stdc++.h>
using namespace std;
char res[800];
int n, tail, head, i;
int main() {
    char* p=res;
    cin >> n;
    if (n==0) {
        cin>>tail;
        cout<<tail;
        return 0;
    }
    i=n;
    for (; i>=2; --i) {
        cin >> tail;
        if (i==n) head=tail;
        char c=tail>0?'+':'-';
        if (tail) {
            p+=sprintf(p, "%c", c);
            if (abs(tail)!=1)
                p+=sprintf(p, "%d", abs(tail));
            p+=sprintf(p, "x^%d", i);
        }
    }
    cin>>tail;
    if (i==n) head=tail;
    if (tail) {
        char c=tail>0?'+':'-';
        p+=sprintf(p, "%c", c);
        if (abs(tail)!=1)
            p+=sprintf(p, "%d", abs(tail));
        p+=sprintf(p, "x");
    }
    cin>>tail;
    if (tail)
        sprintf(p, "%c%d", tail>0?'+':'-', abs(tail));
    char *s = res;
    if (head>0) ++s;
    printf("%s", s);
}

