#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> Solutions;
typedef vector<int> Solution;
Solutions notebook[105][100005];
Solutions recurse(int start, int sum) {
    if (!notebook[start][sum].empty())return notebook[start][sum];
    int start_save = start;
    if (start>sum) return {};
    if (start==sum) return {{start}};
    Solutions result, current;
    for (;; ++start) {
        current = recurse(start+1, sum-start);
        if (current.empty()) {
            result.push_back({sum});
            notebook[start_save][sum] = result;
            return result;
        }
        else {
            for (auto &c:current) {
                c.push_back(start);
            }
            result.insert(result.end(), current.begin(), current.end());
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    __int128_t max_product=0;
    Solutions results = recurse(2, n);
    Solution solution;
    for (auto &result:results) {
        __int128_t product=1;
        for (auto i:result) product*=i;
        if (product > max_product) {
            solution = result;
            max_product = product;
        }
    }
    for (auto p = solution.end()-1;p>=solution.begin();--p) {
        printf("%d ", *p);
    }
    putchar('\n');
    char max_prod_str[100];
    int i=0;
    for (; max_product!=0;++i) {
        max_prod_str[i] = '0'+max_product%10;
        max_product/=10;
    }
    for (int j=i-1; j>=0; --j) {
        putchar(max_prod_str[j]);
    }
}

