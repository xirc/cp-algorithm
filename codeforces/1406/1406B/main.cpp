#include <bits/stdc++.h>

using namespace std;

long long solve(vector<int>& A) {
    assert(A.size() >= 5);
    const auto inf = numeric_limits<long long>::max();
    vector<long long> maxi(5, -inf);
    vector<long long> mini(5, inf);
    for (int i = 0; i < A.size(); ++i) {
        const int v = A[i];
        for (int j = min(i,4); j > 0; --j) {
            if (v >= 0) {
                maxi[j] = max(maxi[j], maxi[j-1] * v);
                mini[j] = min(mini[j], mini[j-1] * v);
            } else {
                maxi[j] = max(maxi[j], mini[j-1] * v);
                mini[j] = min(mini[j], maxi[j-1] * v);
            }
        }
        maxi[0] = max(maxi[0], (long long)v);
        mini[0] = min(mini[0], (long long)v);
    }
    return maxi[4];
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