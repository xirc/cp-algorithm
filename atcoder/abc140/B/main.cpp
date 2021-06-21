#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> A, B, C;

    cin >> N;
    A.assign(N, 0);
    B.assign(N, 0);
    C.assign(N-1, 0);

    for (auto &a : A) cin >> a;
    for (auto &b : B) cin >> b;
    for (auto &c : C) cin >> c;

    int score = 0;
    for (int i = 0; i < N; ++i) {
        score += B[i];
        if (i > 0 && A[i] == A[i-1] + 1) score += C[A[i-1]-1];
    }
    cout << score << endl;

    return 0;
}