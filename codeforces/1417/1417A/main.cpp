#include <bits/stdc++.h>

using namespace std;

// O(N)
int solve(int N, int K, vector<int> const& A) {
    assert(A.size() == N);
    int ans = 0;
    auto min_index = distance(A.begin(), min_element(A.begin(), A.end()));
    for (int i = 0; i < N; ++i) {
        if (i == min_index) continue;
        ans += max(K - A[i], 0) / A[min_index];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N, K;
    vector<int> A;
    
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N >> K;
        A.assign(N, 0);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        cout << solve(N, K, A) << endl;
    }

    return 0;
}