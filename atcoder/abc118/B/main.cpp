#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> A;

int solve() {
    vector<int> B(M, 0);
    for (auto const& vs : A) {
        for (auto v : vs) {
            ++B[v];
        }
    }
    int ans = 0;
    for (auto v : B) {
        if (v == N) ++ans;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int K;
    cin >> N >> M;
    A.assign(N, vector<int>());
    for (int i = 0; i < N; ++i) {
        cin >> K;
        A[i].assign(K, 0);
        for (int j = 0; j < K; ++j) {
            cin >> A[i][j];
            --A[i][j];
        }
    }
    cout << solve() << endl;

    return 0;
}