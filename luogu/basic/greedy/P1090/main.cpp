#include <stdio.h>
#include <algorithm>
using namespace std;
int heaps[10005];
int coheaps[10005];
int n;
int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",&heaps[i]);
    }
    sort(heaps+1,heaps+n+1);
    int p=1,q=n+1;
    int cp=1,cq=1;
    int sum=0;
    bool flag=true;
    while (flag) {
        flag=false;
        int min=2147483647;
        int s1=0,s2,s3;
        if (q-p>=2) {
            flag=true;
            s1=heaps[p]+heaps[p+1];
            min=s1;
        }
        if (cq-cp>=2) {
            flag=true;
            s2=coheaps[cp]+coheaps[cp+1];
            if (s2<min) min=s2;
        }
        if (cq-cp>=1&&q-p>=1) {
            flag=true;
            s3=coheaps[cp]+heaps[p];
            if (s3<min) min=s3;
        }
        if (!flag) break;
        sum+=min;
        coheaps[cq++]=min;
        if (min==s1) {
            p+=2;
        } else if (min==s2) {
            cp+=2;
        } else {
            ++p;
            ++cp;
        }
    }
    printf("%d",sum);
}