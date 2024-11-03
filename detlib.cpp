inline void apply(int l1, int l2, double sc) {
    for (int i=1; i<=n; ++i) {
        mat[l2][i] += mat[l1][i]*sc;
    }
}
double ans = 1.;
double det(double **mat, int n) {
    double ans = 1.;
    for (int i=1; i<=n-1; ++i) {
        for (int j=i+1; j<=n; ++j) {
            apply(i, j, -mat[j][i]/mat[i][i]);
        }
    }
    for (int i=1; i<=n; ++i) {
        ans*=mat[i][i];
    }
    return ans;
}
