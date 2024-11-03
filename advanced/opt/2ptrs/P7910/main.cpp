#include <bits/stdc++.h>
using namespace std;
int n, q;
int arr[8005];
int i2r[8005];
int r2i[8005];
pair<int, int> fs(int x) {
    int l, r;
    for (int i=1; i<=n; ++i) {
        if (arr[i] == x) {
            l = i2r[i];
            r = i2r[i];
            // arr[r2i[r]]
            while (l>=1&&arr[r2i[l]]==x) --l;
            ++l;
            while (r<=n&&arr[r2i[r]]==x) ++r;
            break;
        }
    }
    return {l, r};
}
bool cmp(int r1, int r2) {
    int i1, i2;
    bool f1=false, f2=false;
    for (int i=1; i<=n; ++i) {
        if (f1&&f2) break;
        if (i2r[i]==r1) {
            i1=i;f1=true;
        }
        if (i2r[i]==r2) {
            i2=i;f2=true;
        }
    }
    return arr[i1] < arr[i2];
}
int main() {
    scanf("%d%d", &n, &q);
    for (int i=1; i<=n; ++i) {
        scanf("%d", &arr[i]);
        i2r[i] = i;
        r2i[i] = i;
    }
    sort(i2r+1, i2r+n+1, cmp);
    for (int i=1; i<=q; ++i) {
        int op, x, v, qi;
        scanf("%d", &op);
        if (op==1) {
            // modify
            scanf("%d%d", &x, &v);
            arr[x] = v;
            pair<int, int> S = fs(v);
            if (S.first<=x&&x<S.second) continue;
            else if (x<S.first) {
                // set rank of x to S.first -1
                i2r[x] = i2r[S.first-1];
                for (int j=x+1; j<=S.first-1; ++j) i2r[j]--;
                r2i[S.first-1] = x;
                for (int r=)
            } else {
                i2r[x] = i2r[S.second];
                for (int j=S.second; j<=x-1; ++j) i2r[j]++;
            }
        } else {
            // output
            scanf("%d", &qi);
            printf("%d\n", i2r[qi]);
        }
    }
    return 0;
}
