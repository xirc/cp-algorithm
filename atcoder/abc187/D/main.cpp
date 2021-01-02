#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
vector<vector<ll>> AB;

int solve() {
    sort(AB.begin(), AB.end(), [&](auto& lhs, auto& rhs) {
        return 2 * lhs[0] + lhs[1] < 2 * rhs[0] + rhs[1];
    });
    reverse(AB.begin(), AB.end());

    ll aoki = 0, taka = 0;
    for (int i = 0; i < N; ++i) {
        aoki += AB[i][0];
    }
    for (int i = 0; i < N; ++i) {
        taka += AB[i][0] + AB[i][1];
        aoki -= AB[i][0];
        if (taka > aoki) {
            return i + 1;
        }
    }
    return N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    AB.assign(N, vector<ll>(2));
    for (int i = 0; i < N; ++i) {
        cin >> AB[i][0] >> AB[i][1];
    }
    cout << solve() << endl;

    return 0;
}