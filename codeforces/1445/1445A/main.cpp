#include <bits/stdc++.h>

using namespace std;

bool solve(int N, int X, vector<int>& A, vector<int>& B) {
    reverse(B.begin(), B.end());
    for (int i = 0; i < N; ++i) {
        if (A[i] + B[i] > X) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    int N, X;
    vector<int> A, B;
    
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N >> X;
        A.assign(N, 0);
        B.assign(N, 0);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }
        auto ans = solve(N, X, A, B) ? "Yes" : "No";
        cout << ans << endl;
    }

    return 0;
}