#include <bits/stdc++.h>

using namespace std;

// O(N log N)
bool solve(vector<int>& A) {
    const int N = A.size();
    sort(A.begin(), A.end());
    for (int i = 1; i < N; ++i) {
        if (abs(A[i] - A[i-1]) > 1) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N;
    vector<int> A;

    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> N;
        A.assign(N, 0);
        for (int j = 0; j < N; ++j) {
            cin >> A[j];
        }
        auto ans = solve(A) ? "YES" : "NO";
        cout << ans << endl;
    }

    return 0;
}