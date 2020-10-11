#include <bits/stdc++.h>

using namespace std;

int solve(int N, vector<int>& A) {
    assert(N >= 1);

    int x = A[0];
    for (int v : A) {
        x = min(x, v);
    }

    int nx = x;
    do {
        x = nx;
        for (int i = 0; i < N; ++i) {
            int K = (A[i] - 1) / x;
            A[i] -= K * x;
            nx = min(nx, A[i]);
        }
    } while (nx != x);
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> A;

    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout << solve(N, A) << endl;

    return 0;
}