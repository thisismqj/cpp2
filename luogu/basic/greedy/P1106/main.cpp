#include <bits/stdc++.h>
using namespace std;
char num[255];
char result[255];
int main() {
    int p=1;
    scanf("%s", (num+1));
    int k;
    scanf("%d", &k);
    int l=strlen(num+1);
    k=l-k-1;
    int index=1;
    while (k>=0) {
        int min=INT_MAX;
        for (int i=index;i<=l-k;++i) {
            if (num[i]<min) {
                index=i;
                min=num[i];
            }
        }
        result[p++]=num[index];
        index++;
        --k;
    }
    printf("%s", result+1);
    return 0;
}
