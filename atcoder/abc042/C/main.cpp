#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, K;
vector<int> D;

int solve() {
    vector<bool> ds(10, true);
    for (auto d : D) ds[d] = false;
    auto pass = [&](int m) { 
        while (m > 0) {
            if (!ds[m % 10]) return false;
            m /= 10;
        }
        return true;
    };

    for (int m = N; m <= 90000; ++m) {
        if (pass(m)) return m;
    }
    throw;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    D.assign(K, 0);
    for (int i = 0; i < K; ++i) {
        cin >> D[i];
    }
    cout << solve() << endl;

    return 0;
}