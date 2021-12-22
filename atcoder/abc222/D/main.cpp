#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll const MOD = 998244353;
int N;
vector<int> A, B;

void fold(vector<int>& arr) {
    int const m = arr.size();
    for (int i = m - 2; i >= 0; --i) {
        arr[i] += arr[i+1];
        arr[i] %= MOD;
    }
}

int solve() {
    for (int i = 0; i < N; ++i) {
        if (A[i] > B[i]) return 0;
    }

    int const M = 3001;
    vector<int> cur(M, 0);
    for (int i = A[N-1]; i <= B[N-1]; ++i) {
        cur[i] = 1;
    }
    fold(cur);
    for (int i = N - 2; i >= 0; --i) {
        vector<int> next(M, 0);
        for (int j = A[i]; j <= B[i]; ++j) {
            next[j] += cur[j];
            next[j] %= MOD;
        }
        fold(next);
        cur = next;
    }
    return cur[0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0); B.assign(N, 0);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];
    cout << solve() << endl;

    return 0;
}