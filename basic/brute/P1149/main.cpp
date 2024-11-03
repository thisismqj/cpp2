#include <bits/stdc++.h>
using namespace std;
int sticks[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int count(int x) {
    if (x==0) return 6;
    int digits[5], i;
    for (i=0; x!=0; ++i) {
        digits[i] = x%10;
        x/=10;
    }
    int sum=0;
    for (int j=0; j<i; ++j)
        sum+=sticks[digits[j]];
    return sum;
}
int main() {
    int n;
    scanf("%d", &n);
    n-=4;
    int result=0;
    for (int i=0; i<=111; ++i)
        for (int j=i; j<1111; ++j) {
            int sum=0;
            sum+=(count(i)+count(j)+count(i+j));
            if (sum==n) {
                ++result;
                if (i!=j) ++result;
            }
        }
    printf("%d", result);
}

