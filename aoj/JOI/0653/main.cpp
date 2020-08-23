#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> X, A;

void solve() {
    const int L = 2020;
    for (auto ai : A) {
        int ub = ai + 1 < N ? X[ai+1] : L;
        if (X[ai] + 1 < ub) {
            ++X[ai];
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << X[i] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    X.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }
    cin >> M;
    A.assign(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> A[i];
        --A[i];
    }
    solve();

    return 0;
}