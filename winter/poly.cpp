#include <bits/stdc++.h>
using namespace std;
bool prime[100005];
int main() {
    memset(prime, 1, sizeof(prime));
    int s;
    cin>>s;
    int sum=0, cnt=0;
    for (int i=2; ; ++i) {
        if (prime[i]) {
            sum+=i;
            if (sum>s) {
                cout<<cnt;
                return 0;
            }
            cout<<i<<endl;
            ++cnt;
            for (int j=2*i; j<=s-sum; j+=i) {
                prime[j] = false;
            }
        }
    }
    return 0;
}
