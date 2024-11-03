#include <bits/stdc++.h>
using namespace std;
// maintain an increasing queue
// move from left: if front index==left, then pop
// move to right: push if back < right
// max is the back of the queue
deque<int> dq;
int arr[2000005];
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i=1; i<=n; ++i) {
        int x;
        scanf("%d", &x);
        arr[i] = x;
        // if x < back(or empty) then push
        // else pop(back) until empty or x < back
    }
    for (int i=1; i<=k; ++i) {
        int x = arr[i];
        while (!dq.empty()&&x>=arr[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }
    // pop front until in date(out date<=> front < i)
    // get next num, pop back until back > next num
    for (int i=1; i<=n-k; ++i) {
        while (dq.front()<i) dq.pop_front();
        printf("%d\n", arr[dq.front()]);
        int nn = arr[i+k];
        while (!dq.empty()&&arr[dq.back()]<=nn) dq.pop_back();
        dq.push_back(i+k);
    }
    while (dq.front()<n-k+1) dq.pop_front();
    printf("%d\n", arr[dq.front()]);
    return 0;
}
