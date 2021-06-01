#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll N, K;
vector<array<ll,2>> AB;

ll solve() {
    sort(AB.begin(), AB.end());

    ll pos = 0;
    ll coins = K;
    auto it = AB.begin();
    while (coins > 0) {
        pos += coins;
        coins = 0;
        while (it != AB.end() && (*it)[0] <= pos) {
            coins += (*it)[1];
            ++it;
        }
    }
    return pos;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    AB.assign(N, { 0, 0 });
    for (int i = 0; i < N; ++i) {
        cin >> AB[i][0] >> AB[i][1];
    }
    cout << solve() << endl;

    return 0;
}