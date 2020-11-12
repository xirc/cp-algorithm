#include <bits/stdc++.h>

using namespace std;

int solve(int N, vector<int> const& A) {
    assert(N > 0);
    int K = *max_element(A.begin(), A.end());
    int index = -1;
    for (int i = 0; i < N; ++i) {
        if (A[i] != K) continue;
        if (i - 1 >= 0 && A[i-1] < K) {
            index = i + 1;
            break;
        }
        if (i + 1 < N && A[i+1] < K) {
            index = i + 1;
            break;
        }
    }
    return index;
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
        cout << solve(N, A) << endl;
    }

    return 0;
}