#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, D;
vector<vector<int>> X;

int magnitude(vector<int> const& a, vector<int> const& b) {
    int mag = 0;
    for (int i = 0; i < D; ++i) {
        int c = a[i] - b[i];
        mag += c * c;
    }
    return mag;
}

int solve() {
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int mag = magnitude(X[i], X[j]);
            int sqrtMag = round(sqrtl(mag));
            if (mag == sqrtMag * sqrtMag) {
                ++ans;
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> D;
    X.assign(N, vector<int>(D, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < D; ++j) {
            cin >> X[i][j];
        }
    }
    cout << solve() << endl;

    return 0;
}