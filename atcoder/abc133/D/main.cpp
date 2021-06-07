#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<int> A;

vector<int> solve() {
    vector<int> X(N, 0);
    int X0 = 0;
    for (int i = 0; i < N; ++i) {
        int sign = i % 2 == 0 ? 1 : -1;
        X0 +=  sign * A[i];
    }
    X[0] = X0;
    for (int i = 1; i < N; ++i) {
        X[i] = (A[i-1] - X[i-1] / 2) * 2;
    }
    return X;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0);
    for (auto &a : A) cin >> a;
    auto X = solve();
    for (int i = 0; i < N; ++i) {
        if (i > 0) cout << " ";
        cout << X[i];
    }
    cout << endl;

    return 0;
}