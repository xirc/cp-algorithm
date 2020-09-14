#include <bits/stdc++.h>

using namespace std;

// O(N)
long long solve(vector<int> const& A) {
    long long neg = 0;
    for (auto it = A.rbegin(); it != A.rend(); ++it) {
        long long ai = *it;
        if (ai < 0) {
            neg -= ai;
        } else {
            long long c = min(neg, ai);
            neg -= c;
        }
    }
    return neg;
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
        cout << solve(A) << endl;
    }

    return 0;
}