#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int>& A) {
    int mini = *min_element(A.begin(), A.end());

    vector<int> sortedA = A;
    sort(sortedA.begin(), sortedA.end());

    for (int i = 0; i < A.size(); ++i) {
        if (A[i] == sortedA[i]) continue;
        if (A[i] % mini != 0) return false;
    }
    return true;
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