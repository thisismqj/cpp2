#include <bits/stdc++.h>
using namespace std;
char square[105][105];
char result[105][105];
int dx[8] = {-6, -6, -6, 0, 6, 6, 6, 0};
int dy[8] = {-6, 0, 6, 6, 6, 0, -6, -6};
const char str[] = "yizhong";
int n;
int main() {
    memset(result, '*', sizeof(result));
    scanf("%d", &n);
    for (int i=1; i<=n; ++i) {
            scanf("%s", square[i]+1);
    }
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            if (square[i][j]=='y') {
                for (int k=0; k<8; ++k) {
                    int x = i+dx[k], y=j+dy[k];
                    if (x>=1&&x<=n&&y>=1&&y<=n&&square[x][y]=='g') {
                        int ddx = dx[k] / 6;
                        int ddy = dy[k] / 6;
                        bool match = true;
                        for (int l=1; l<=5; ++l) {
                            if (square[i+l*ddx][j+l*ddy]!=str[l]) {
                                match = false;
                                break;
                            }
                        }
                        if (match) {
                            for (int l=0; l<=6; ++l) {
                                result[i+l*ddx][j+l*ddy] = str[l];
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j){
            putchar(result[i][j]);
        }
        putchar('\n');
    }
    return 0;
}

