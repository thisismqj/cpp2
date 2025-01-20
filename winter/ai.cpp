#include <bits/stdc++.h>
using namespace std;
int n, d;
int Q[10005*25], KT[25*10005], V[10005*25], W[10005*1], ans1[10005*25], ans2[10005*25], ans3[10005*25];
void mat_mul(int *x, int *y, int *z, int h, int w, int m) {
    for (int i=0; i<h; ++i)
        for (int j=0; j<w; ++j) {
            *(z+i*w+j) = 0;
            for (int k=0; k<m; ++k) {
                //*(z+i*h+j)=x[i][k]*y[k][j];
                *(z+i*w+j)=*(x+i*m+k) * (*(y+k*w+j));
            }
        }
}
void dot(int *v, int *m, int *ans, int h, int w) {
    for (int i=0; i<h; ++i) {
        for (int j=0; j<w; ++j) {
            // ans[i][j] = v[i][0]*m[i][j]
            *(ans+i*w+j) = *(v+i) * (*(m+i*w+j));
        }
    }
}
void inp(int *x, int h, int w) {
    for (int i=0; i<h; ++i) {
        for (int j=0; j<w; ++j) {
            cin>>*(x+i*w+j);
        }
    }
}
void inpt(int *x, int h, int w) {
    for (int i=0; i<h; ++i) {
        for (int j=0; j<w; ++j) {
            cin>>*(x+j*h+i);
        }
    }
}
void outp(int *x, int h, int w) {
    for (int i=0; i<h; ++i) {
        for (int j=0; j<w; ++j) {
            cout<<*(x+i*w+j)<<' ';
        }
        cout<<endl;
    }
}
int main() {
    inp(Q, n, d);
    inpt(KT, n, d);
    inp(V, n, d);
    inp(W, n, 1);
    mat_mul(Q, KT, ans1, n, n, d);
    dot(W, ans1, ans2, n, n);
    mat_mul(ans2, V, ans3, n, d, n);
    outp(ans3, n, d);
    return 0;
}

