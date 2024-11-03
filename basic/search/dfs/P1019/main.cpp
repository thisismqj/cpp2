#include <bits/stdc++.h>
using namespace std;
char str[21][17];
int len[21];
int bucket[21];
int n;
const int RESULT_LEN = 105;
int result_len;
int max_len;
char result[RESULT_LEN];
void dfs() {
    if (result_len > max_len) max_len = result_len;
    for (int i=1; i<=n; ++i) {
        if (bucket[i]<2) {
            int j0;
            for (j0 = result_len-1; 
            j0>=max(1, result_len-len[i]+1); --j0) {
                int i1 = 0;
                bool match = true;
                for (int j=j0; j<=result_len-1; ++j, ++i1) {
                    if (i1 >= len[i]||result[j]!=str[i][i1]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    ++bucket[i];
                    strcpy(result+j0, str[i]);
                    int old_result_len = result_len;
                    result_len = j0 + len[i];
                    dfs();
                    result_len = old_result_len;
                    memset(result+result_len, 0, RESULT_LEN-result_len);
                    --bucket[i];
                    break;
                }
            }
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; ++i) {
        scanf("%s", str[i]);
        len[i] = strlen(str[i]);
    }
    scanf("%s", result);
    for (int i=1; i<=n; ++i) {
        if (str[i][0] == result[0]) {
            ++bucket[i];
            if (max_len < len[i])
                max_len = len[i];
            result_len = len[i];
            memset(result, 0, RESULT_LEN);
            strcpy(result, str[i]);
            dfs();
            --bucket[i];
        }
    }
    printf("%d", max_len);
    return 0;
}

