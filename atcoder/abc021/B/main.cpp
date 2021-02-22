#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, a, b, K;
vector<int> P;

bool solve() {
    vector<bool> visited(N, false);
    visited[a] = visited[b] = true;
    for (auto p : P) {
        if (visited[p]) return false;
        visited[p] = true;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> a >> b >> K;
    --a, --b;
    P.assign(K, 0);
    for (auto& p : P) {
        cin >> p;
        --p;
    }

    auto ans = solve() ? "YES" : "NO";
    cout << ans << endl;

    return 0;
}