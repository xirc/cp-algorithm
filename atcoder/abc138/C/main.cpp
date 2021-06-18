#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> vs;

    cin >> N;
    vs.assign(N, 0);
    for (auto &v : vs) cin >> v;

    priority_queue<ff> Q;
    for (auto v : vs) Q.push(-v);

    while (Q.size() >= 2) {
        auto a = -Q.top(); Q.pop();
        auto b = -Q.top(); Q.pop();
        auto c = (a + b) / 2.0;
        Q.push(-c);
    }

    ff ans = -Q.top();
    cout << fixed << setprecision(6) << ans << endl;

    return 0;
}