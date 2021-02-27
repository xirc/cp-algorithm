#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> A;

    cin >> N;
    A.assign(N, 0);
    for (auto &ai : A) cin >> ai;

    vector<ll> mark(N, 0);
    mark[0] = 0;
    mark[1] = abs(A[0] - A[1]);
    for (int i = 2; i < N; i++) {
        mark[i] = min(
            abs(A[i] - A[i-1]) + mark[i-1],
            abs(A[i] - A[i-2]) + mark[i-2]
        );
    }
    cout << mark[N-1] << endl;

    return 0;
}