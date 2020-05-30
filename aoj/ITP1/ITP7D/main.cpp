#include <bits/stdc++.h>

using namespace std;
using vec = vector<long long>;
using mat = vector<vec>;

mat scan(int r, int c) {
    mat M(r, vec(c, 0));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> M[i][j];
        }
    }
    return M;
}

void print(const mat& M) {
    for (int i = 0; i < M.size(); ++i) {
        for (int j = 0; j < M[i].size(); ++j) {
            if (j > 0) cout << " ";
            cout << M[i][j];
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, l;
    cin >> n >> m >> l;

    auto A = scan(n, m);
    auto B = scan(m, l);
    
    mat C = mat(n, vec(l, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < l; ++j) {
            for (int k = 0; k < m; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    print(C);

    return 0;
}