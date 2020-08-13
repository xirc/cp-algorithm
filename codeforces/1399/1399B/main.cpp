#include <bits/stdc++.h>

using namespace std;

long long solve(const int N, const vector<int>& A, const vector<int>& B) {
    long long ans = 0;
    const int minA = *min_element(A.begin(), A.end());
    const int minB = *min_element(B.begin(), B.end());
    for (int i = 0; i < N; ++i) {
        const int diffA = A[i] - minA;
        const int diffB = B[i] - minB;
        const int minDiffAB = min(diffA, diffB);
        ans += (long long)diffA + diffB - minDiffAB;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N;
    vector<int> A, B;

    cin >> T;
    for (int t = 0; t < T; ++t) {
        cin >> N;
        A.assign(N, 0);
        B.assign(N, 0);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }
        auto ans = solve(N, A, B);
        cout << ans << endl;
    }

    return 0;
}