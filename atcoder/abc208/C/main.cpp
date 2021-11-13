#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    ll K;
    vector<int> A;

    cin >> N >> K;
    A.assign(N, 0);
    for (auto &a : A) cin >> a;

    auto B = A;
    sort(B.begin(), B.end());
    int m = B[K % N];
    for (int i = 0; i < N; ++i) {
        ll num_snacks = K / N;
        if (A[i] < m) num_snacks += 1;
        cout << num_snacks << endl;
    }

    return 0;
}