#include <stack>
int ans=0;
stack<int> s;
void play(int n) {
    s.push(n);
    while (!s.empty()) {
        int i = s.pop();
        ans+=i;
        if (i!=2||i!=1) {
            s.push(i-2);
            s.push(i-1);
        }
    }
}
