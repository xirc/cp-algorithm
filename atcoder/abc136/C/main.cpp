#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<int> H;

bool solve() {
    for (int i = 1; i < N; ++i) {
        if (H[i] > H[i-1]) --H[i];
    }
    for (int i = 0; i + 1 < N; ++i) {
        if (H[i] > H[i+1]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    H.assign(N, 0);
    for (auto &hh : H) cin >> hh;
    auto ans = solve() ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}