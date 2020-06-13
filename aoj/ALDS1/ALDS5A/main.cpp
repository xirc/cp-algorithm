#include <bits/stdc++.h>

using namespace std;

vector<int> A;

// O(2^N)
bool solve(int M, int i = 0, int sum = 0) {
    if (sum == M) return true;
    if (i == A.size()) return false;
    if (solve(M, i+1, sum)) {
        return true;
    }
    return solve(M, i+1, sum+A[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int M;
        cin >> M;
        bool ans = solve(M);
        cout << (ans ? "yes" : "no") << endl;
    }

    return 0;
}