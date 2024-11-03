#include <bits/stdc++.h>
using namespace std;
int p, k;
char s[205];
char base_dict[7][205];
char *dict[7];
int word_len[7];
int s_word[205];
int f[205][41];
int dict_len;
int mystrstr(char* s, char* p) {
	int s_len = strlen(s);
	int p_len = strlen(p);
	int* nxt = (int *)calloc(p_len, sizeof(int));
    int i=0, j=1;
    while (j<p_len) {
        if (p[i]==p[j]) {
            if (i!=j) nxt[j] = i+1;
            ++i;++j;
        } else {
            while (i!=0) {
                i=nxt[i-1];
                if (p[i]==p[j]) {
                    nxt[j] = i+1;
                    ++i;
                    break;
                }
            }
            ++j;
        }
    }
    i=0;j=0;
    while (s_len-i>=p_len-j) {
        if (s[i]==p[j]) {
            if (j==p_len-1) {
                return i-p_len+1;
            }
            ++i;++j;
        } else {
            while (j!=0) {
                j = nxt[j-1];
                if (s[i]==p[j]) {
                    ++j;
                    break;
                }
            }
            ++i;
        }
    }
    return -1;
}
int word_range[205][205];
int main() {
    scanf("%d%d", &p, &k);
    for (int i=0; i<20*p; ++i) {
        cin>>s[i];
    }
    scanf("%d", &dict_len);
    for (int i=1; i<=dict_len; ++i) {
        scanf("%s", base_dict[i]);
        dict[i] = base_dict[i];
        word_len[i] = strlen(base_dict[i]);
    }
    for (int i=dict_len; i>=2; --i) {
        for (int j=1; j<=i-1; ++j) {
            if (strcmp(dict[j], dict[j+1])>0) {
                int j_len = word_len[j];
                word_len[j] = word_len[j+1];
                word_len[j+1] = j_len;
                char *d = dict[j];
                dict[j] = dict[j+1];
                dict[j+1] = d;
            }
        }
    }
    for (int i=1; i<=dict_len; ++i) {
        int j=0;
        int loc;
        while ((loc=mystrstr(s+j, dict[i]))!=-1) {
            if (s_word[loc+j]==0) {
                s_word[loc+j] =  word_len[i];
            }
            ++j;
        }
    }
    for (int i=0; i<20*p; ++i) {
        if (s_word[i]==1) word_range[i][i] = 1;
    }
    for (int i=1; i<20*p; ++i) {
        for (int j=i-1; j>=0; --j) {
            if (s_word[j]!=0&&j+s_word[j]-1<=i) word_range[j][i] = word_range[j+1][i]+1;
            else word_range[j][i] = word_range[j+1][i];
        }
    }
    for (int i=0; i<20*p; ++i) {
        f[i][1] = word_range[0][i];
    }
    for (int j=2; j<=k; ++j) {
        for (int i=j-1; i<20*p; ++i) {
            for (int x=j-2; x<=i-1; ++x) {
                f[i][j] = max(f[i][j], f[x][j-1]+word_range[x+1][i]);
            }
        }
    }
    printf("%d", f[20*p-1][k]);
}
