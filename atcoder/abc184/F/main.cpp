#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, T;
vector<int> A;

int solve() {
    vector<ll> B, C;
    int const U = N / 2;
    int const V = N - U;
    for (int s = 0; s < (1 << U); ++s) {
        ll sum = 0;
        for (int i = 0; i < U; ++i) {
            if ((s >> i) & 1) {
                sum += A[i];
            }
        }
        B.push_back(sum);
    }
    for (int s = 0; s < (1 << V); ++s) {
        ll sum = 0;
        for (int i = 0; i < V; ++i) {
            if ((s >> i) & 1) {
                sum += A[U+i];
            }
        }
        C.push_back(sum);
    }

    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    ll max_sum = 0;
    for (int i = 0; i < B.size(); ++i) {
        if (B[i] > T) break;
        ll K = T - B[i];
        auto it = upper_bound(C.begin(), C.end(), K);
        if (it != C.begin()) {
            --it;
            ll sum = B[i] + *it;
            max_sum = max(max_sum, sum);
        }
    }
    return max_sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> T;
    A.assign(N, 0);
    for (auto &ai : A) cin >> ai;
    cout << solve() << endl;

    return 0;
}