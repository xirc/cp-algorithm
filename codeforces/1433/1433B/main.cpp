#include <bits/stdc++.h>

using namespace std;

int solve(int N, vector<int> const& A) {
    auto ones = count_if(A.begin(), A.end(), [](auto v) { return v == 1; });
    if (ones <= 1) return 0;
    int ans = N - ones;

    for (int i = 0; i < N; ++i) {
        if (A[i] == 1) break;
        --ans;
    }
    for (int i = N - 1; i >= 0; --i) {
        if (A[i] == 1) break;
        --ans;
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N;
    vector<int> A;

    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N;
        A.assign(N, 0);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        cout << solve(N, A) << endl;
    }

    return 0;
}