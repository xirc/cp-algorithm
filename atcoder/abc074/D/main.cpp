#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
vector<vector<ll>> A;

ll solve() {
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][k] + A[k][j] < A[i][j]) {
                    return -1;
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            bool pass = true;
            for (int k = 0; k < N; ++k) {
                if (i == k || j == k) continue;
                if (A[i][j] == A[i][k] + A[k][j]) pass = false;
            }
            if (pass) {
                ans += A[i][j];
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, vector<ll>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }
    cout << solve() << endl;

    return 0;
}