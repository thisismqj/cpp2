#include <bits/stdc++.h>
using namespace std;
char input_str_base[20][10];
char *input_str[20];
bool cmp(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len_min, len_max;
    char *s_min, *s_max;
    bool s1_longer; // true for s1, false for s2
    if (len1>len2) {
        len_max = len1;
        len_min = len2;
        s_max = s1;
        s_min = s2;
        s1_longer = true;
    } else {
        len_max = len2;
        len_min = len1;
        s_max = s2;
        s_min = s1;
        s1_longer = false;
    }
    int j;
    for (j=0; j<len_min; ++j) {
        if (s1[j]>s2[j]) {
            return false;
        }
        if (s1[j]<s2[j]) {
            return true;
        }
    }
    for (int i=0;j+i<len_max;++i) {
        // s1[i]代表s2
        // s_min较小, 是s1返回true
        if (s_max[j+i]>s_max[i]) {
            return !s1_longer;
        }
        if (s_max[j+i]<s_max[i]) {
            return s1_longer;
        }
    }
    return false;
}
int main() {
    for (int i=0; i<20; ++i) {
        input_str[i] = input_str_base[i];
    }
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; ++i)
        scanf("%s", input_str[i]);
    sort(input_str, input_str+n, cmp);
    for (int i=n-1; i>=0; --i) {
        printf("%s", input_str[i]);
    }
}

