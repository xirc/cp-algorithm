#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int N;
vector<int> C;

int solve() {
    int const inf = 1e8;
    vector<int> A(N, inf);
    for (int i = 0; i < N; ++i) {
        auto it = lower_bound(A.begin(), A.end(), C[i]);
        *it = C[i];
    }
    for (int i = N-1; i > 0; --i) {
        if (A[i] == inf) continue;
        return N - (i+1);
    }
    return N-1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    C.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
    }
    cout << solve() << endl;

    return 0;
}