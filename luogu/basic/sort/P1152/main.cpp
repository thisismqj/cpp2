#include <bits/stdc++.h>
using namespace std;
bool checked[200000005];
int main() {
    int n;
    scanf("%d", &n);
    int last, current;
    scanf("%d", &last);
    for (int i=1; i<n; ++i) {
        int diff;
        scanf("%d", &current);
        diff = abs(current-last);
        if (diff > n-1|| diff<1) {
            printf("Not jolly");
            return 0;
        } else if (!checked[diff]) {
            checked[diff] = true;
            last = current;
        } else {
            printf("Not jolly");
            return 0;
        }
    }
    printf("Jolly");
    return 0;
}

