#include <iostream>
using namespace std;
int arr[505][505];
int main() {
    int n, m;
    int x, y, rad, z;
    cin >> n >> m;
    for (int i=1; i<=n; ++i) 
        for (int j=1; j<=n; ++j)
            arr[i][j]=(n*(i-1)+j);
    for (;m>0;--m) {
        cin >> x >> y >> rad >> z;
        int l=y-rad, r=y+rad, u=x-rad, d=x+rad;
        if (z) {
            for (int i=u; i<=d-1; ++i)
                for (int j=l; j<=l+d-i-1; ++j)
                    swap(arr[i][j], arr[u+r-j][u+r-i]);
            //print(n);
        } else {
            for (int i=u+1; i<=d; ++i)
                for (int j=l; j<=l+i-u-1; ++j)
                    swap(arr[i][j], arr[j+u-l][i+l-u]);
            //print(n);
        }
        for (int j=l; j<(l+r)/2;++j) {
            for (int i=u; i<=d; ++i)
                swap(arr[i][j], arr[i][l+r-j]);
        }
        //print(n);
    }
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j)
            cout << arr[i][j] << " ";
        cout<<endl;
    }
}

void print(int n) {
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j)
            cout << arr[i][j] << " ";
        cout<<endl;
    }
}