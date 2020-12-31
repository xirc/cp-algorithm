#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, A, B;
vector<int> H;

bool is_ok(const ll M) {
    int mxh = *max_element(H.begin(), H.end());
    if (mxh / B < M) return true; // prevent an overflow
    assert(B * M <= mxh);

    const int C = A - B;
    assert(C > 0);
    ll mm = M;
    for (auto hi : H) {
        if (hi - B * M <= 0) continue;
        ll mi = (hi - B * M + (C - 1)) / C;
        assert(mi > 0);
        mm -= mi;
        if (mm < 0) return false;
    }
    return true;
}

ll solve() {
    ll low = 0, high = 1e15;
    assert(!is_ok(low) && is_ok(high));
    while (high - low > 1) {
        auto m = low + (high - low) / 2;
        if (is_ok(m)) {
            high = m;
        } else {
            low = m;
        }
    }
    return high;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> A >> B;
    H.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    cout << solve() << endl;

    return 0;
}