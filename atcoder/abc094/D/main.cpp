#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;

vector<int> solve() {
    sort(A.begin(), A.end());
    int nn = A[N-1];
    int kk = A[0];
    for (int i = 1; i < N; ++i) {
        int p = abs(A[i] - (nn - A[i]));
        int bp = abs(kk - (nn - kk));
        if (p < bp) {
            bp = p;
            kk = A[i];
        }
    }
    return { nn, kk };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    auto ans = solve();
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}