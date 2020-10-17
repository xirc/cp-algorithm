#include <bits/stdc++.h>

using namespace std;

bool solve(int N, vector<int> & A) {
    int sum = accumulate(A.begin(), A.end(), 0, plus<int>());
    if (sum == 0) return 0;
    sort(A.begin(), A.end());
    if (sum > 0) reverse(A.begin(), A.end());
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
        auto ans = solve(N, A);
        cout << (ans ? "YES" : "NO") << endl;
        if (ans) {
            for (int i = 0; i < N; ++i) {
                if (i > 0) cout << " ";
                cout << A[i];
            }
            cout << endl;
        }
    }

    return 0;
}