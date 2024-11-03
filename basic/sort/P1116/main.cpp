#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int main() {
    int n, sum=0;
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        scanf("%d", &arr[i]);
        for (int j=i-1; j>=0; --j) {
            if (arr[i] < arr[j])
                ++sum;
        }
    }
    printf("%d", sum);
}

