#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> const& A, int X) {
    bool are_all_infected = all_of(A.begin(), A.end(), [&](const auto& value) {
        return value == X;
    });
    if (are_all_infected) return 0;

    bool exists_infected = any_of(A.begin(), A.end(), [&](const auto& value) {
        return value == X;
    });
    if (exists_infected) return 1;

    int sum = accumulate(A.begin(), A.end(), 0, [&](const auto& acc, const auto& value) {
        return acc + (value - X);
    });
    if (sum == 0) return 1;

    return 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T, N, X;
    vector<int> A;

    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N >> X;
        A.assign(N, 0);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        cout << solve(A, X) << endl;
    }

    return 0;
}