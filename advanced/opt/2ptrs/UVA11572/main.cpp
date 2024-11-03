#include <bits/stdc++.h>
using namespace std;
// HashBucket
// insert(x): inc cnt of x
// query(x): return cnt of x
struct HashBucket {
    void insert(int x) {
        int xmod = x%10007;
        if (arr[xmod].empty()) arr[xmod].push_back({x, 1});
        else {
            for (auto &c: arr[xmod]) {
                if (c.first==x) {++c.second;return;}
            }
            arr[xmod].push_back({x, 1});
        }
    }
    void remove(int x) {
        int xmod = x%10007;
        for (auto &c: arr[xmod]) {
            if (c.first==x) {--c.second;return;}
        }
    }
    int query(int x) {
        int xmod = x%10007;
        if (arr[xmod].empty()) return 0;
        else {
            for (auto c: arr[xmod]) {
                if (c.first==x) return c.second;
            }
            return 0;
        }
    }
    void clear() {
        for (int i=0; i<10007; ++i)
            arr[i].clear();
    }
    vector<pair<int, int>> arr[10007];
} hashb;
int arr[1000005];
int main() {
    int n, m;
    scanf("%d", &n);
    for (int i=1; i<=n; ++i) {
        hashb.clear();
        scanf("%d", &m);
        for (int j=1; j<=m; ++j) {
            scanf("%d", &arr[j]);
        }
        int l = 1, r = 1;
        int ans = 0;
        while (true) {
            if (r>m) break;
            hashb.insert(arr[r]);
            int cnt = hashb.query(arr[r]);
            if (cnt==1) {
                ++r; 
                ans = max(r-l, ans);
                if (r>m) {
                    break;
                }
            } else {
                ++r;
                while (true) {
                    hashb.remove(arr[l]);
                    if (hashb.query(arr[l])==1) {++l;break;}
                    ++l;
                }
                ans = max(r-l, ans);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
