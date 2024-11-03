#include <bits/stdc++.h>
using namespace std;
int methods[60000][10];
#define r(a,l, r) for (int a=max(1, l); a<=min(3, r); ++a)
int main() {
    int delic;
    scanf("%d", &delic);
    int methods_count = 0;
    r(a,delic-27,delic-9)
    r(b,delic-a-24,delic-a-8)
    r(c,delic-a-b-21,delic-a-b-7)
    r(d,delic-a-b-c-18,delic-a-b-c-6)
    r(e,delic-a-b-c-d-15,delic-a-b-c-d-5)
    r(f,delic-a-b-c-d-e-12,delic-a-b-c-d-e-4)
    r(g,delic-a-b-c-d-e-f-9,delic-a-b-c-d-e-f-3)
    r(h,delic-a-b-c-d-e-f-g-6,delic-a-b-c-d-e-f-g-2)
    r(i,delic-a-b-c-d-e-f-g-h-3,delic-a-b-c-d-e-f-g-h-1)
    r(j,delic-a-b-c-d-e-f-g-h-i,delic-a-b-c-d-e-f-g-h-i) {
        methods[methods_count][0]=a;
        methods[methods_count][1]=b;
        methods[methods_count][2]=c;
        methods[methods_count][3]=d;
        methods[methods_count][4]=e;
        methods[methods_count][5]=f;
        methods[methods_count][6]=g;
        methods[methods_count][7]=h;
        methods[methods_count][8]=i;
        methods[methods_count][9]=j;
        ++methods_count;
    }
    printf("%d\n", methods_count);
    for (int i=0; i<methods_count; ++i) {
        for (int j=0; j<10; ++j) {
            printf("%d ", methods[i][j]);
        }
        putchar('\n');
    }
}

