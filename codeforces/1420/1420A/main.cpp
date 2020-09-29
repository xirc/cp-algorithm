#include <bits/stdc++.h>

using namespace std;

// Time: O(N)
bool solve(vector<int>& A) {
    // Worst swap count of Bubbble Sort is N * (N - 1) / 2.
    // Therefore, we cannot sort only in worst case.
    const int N = A.size();
    for (int i = 0; i + 1 < N; ++i) {
        if (A[i] <= A[i+1]) return true;
    }
    return false;
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
        auto ans = solve(A) ? "YES" : "NO";
        cout << ans << endl;
    }

    return 0;
}