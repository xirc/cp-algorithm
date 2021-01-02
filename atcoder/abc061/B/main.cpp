#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> A, B;

vector<int> solve() {
    vector<int> count(N, 0);
    for (int i = 0; i < M; ++i) {
        ++count[A[i]];
        ++count[B[i]];
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    A.assign(M, 0);
    B.assign(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> A[i] >> B[i];
        --A[i], --B[i]; //0-indexed
    }
    auto ans = solve();
    for (auto c : ans) {
        cout << c << endl;
    }

    return 0;
}