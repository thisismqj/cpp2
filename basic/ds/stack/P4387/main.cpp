#include <bits/stdc++.h>
using namespace std;
stack<int> st;
int inp[100005];
int inp_p=0;
int p;
int main() {
    scanf("%d", &p);
    for (int i=1; i<=p; ++i) {
        stack<int>().swap(st);
        inp_p=0;
        int l;
        scanf("%d", &l);
        for (int j=0; j<l; ++j) {
            scanf("%d", &inp[j]);
        }
        for (int j=1; j<=l; ++j) {
            int n;
            scanf("%d", &n);
            while (st.empty()||st.top()!=n) {
                if (inp_p==l) {
                    printf("No\n");
                    for (int k=j+1;k<=l;++k)
                        scanf("%d", &n);
                    goto qend;
                } else {
                    st.push(inp[inp_p++]);
                }
            }
            st.pop();
        }
        printf("Yes\n");
    qend:
    }
    return 0;
}
