#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int N) {
    vector<int> X(N, 9);
    for (int i = 0; i < N / 4; ++i) {
        X[i] = 8;
    }
    if (N % 4) {
        X[N/4] = 8;
    }
    reverse(X.begin(), X.end());
    return X;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N;
        auto ans = solve(N);
        for (int dig : ans) {
            cout << dig;
        }
        cout << endl;
    }

    return 0;
}