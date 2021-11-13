#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int P;
    cin >> P;

    vector<int> coins;
    coins.push_back(1);
    for (int i = 2; coins.back() < P; ++i) {
        int n = coins.back() * i;
        coins.push_back(n);
    }
    reverse(coins.begin(), coins.end());

    int ans = 0;
    for (int i = 0; i < coins.size(); ++i) {
        if (P / coins[i] > 0) {
            ans += P / coins[i];
            P %= coins[i];
        }
    }
    cout << ans << endl;

    return 0;
}