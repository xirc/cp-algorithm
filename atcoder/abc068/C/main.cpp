#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> A, B;

bool solve() {
    unordered_set<int> is;
    for (int i = 0; i < M; ++i) {
        if (A[i] == 0) {
            is.insert(B[i]);
        }
        if (B[i] == 0) {
            is.insert(A[i]);
        }
    }
    for (int i = 0; i < M; ++i) {
        if (A[i] == N-1 && is.count(B[i]) > 0) return true;
        if (B[i] == N-1 && is.count(A[i]) > 0) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    A.assign(M, 0);
    B.assign(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> A[i] >> B[i];
        --A[i], --B[i];
    }
    auto ans = solve() ? "POSSIBLE" : "IMPOSSIBLE";
    cout << ans << endl;

    return 0;
}