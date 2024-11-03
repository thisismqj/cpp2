#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
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
            if (j==p_len-1) {r
                return i-p_len+1;
            }
            ++i;++j;
        } else {
            while (j!=0) {
                j = nxt[j];
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
char s[100], p[100];
int main() {
	scanf("%s %s", s, p);
	printf("%d", 1+mystrstr(s, p));
	return 0;
}

