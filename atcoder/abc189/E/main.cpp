#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using vec = vector<ll>;
using mat = vector<vec>;

void dump(mat const& m) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

mat operator*(mat const& a, mat const& b) {
    mat c(3, vec(3, 0));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

vec operator*(mat const& a, vec const& b) {
    vec c(3, 0);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            c[i] += a[i][j] * b[j];
        }
    }
    return c;
}

mat rotate_cw() {
    return {
        { 0, 1, 0 },
        { -1, 0, 0 },
        { 0, 0, 1 },
    };
}

mat rotate_ccw() {
    return {
        { 0, -1, 0 },
        { 1, 0, 0 },
        { 0, 0, 1 },
    };
}

mat mirror_y(int p) {
    return {
        { -1, 0, 2 * p },
        { 0, 1, 0 },
        { 0, 0, 1 },
    };
}

mat mirror_x(int p) {
    return {
        { 1, 0, 0 },
        { 0, -1, 2 * p },
        { 0, 0, 1 },
    };
}

int N, M;
vector<int> X, Y;
vector<vector<int>> ops;

vector<mat> DP;

void build() {
    DP.assign(M + 1, {});
    DP[0] = {
        { 1, 0, 0 },
        { 0, 1, 0 },
        { 0, 0, 1 },
    };
    for (int i = 0; i < M; ++i) {
        auto op = ops[i][0], p = ops[i][1];
        mat m;
        if (op == 1) {
            m = rotate_cw();
        } else if (op == 2) {
            m = rotate_ccw();
        } else if (op == 3) {
            m = mirror_y(p);
        } else if (op == 4) {
            m = mirror_x(p);
        } else throw;
        DP[i+1] = m * DP[i];
    }
}

vector<ll> query(int ai, int bi) {
    auto m = DP[ai];
    vec iv = { X[bi], Y[bi], 1 };
    return m * iv;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    X.assign(N, 0);
    Y.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> Y[i];
    }

    cin >> M;
    for (int i = 0; i < M; ++i) {
        int op, p;
        cin >> op;
        if (op == 3 || op == 4) {
            cin >> p;
        } else {
            p = 0;
        }
        ops.push_back({ op, p });
    }

    build();

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        --bi;
        auto ans = query(ai, bi);
        cout << ans[0] << " " << ans[1] << endl;
    }

    return 0;
}