#include <bits/stdc++.h>

using namespace std;

int N, C0, C1, H;
string S;

int solve() {
    int pay_coins = 0;
    for (auto c : S) {
        int coins;
        if (c == '0') {
            coins = min(C0, C1 + H);
        } else {
            coins = min(C1, C0 + H);
        }
        pay_coins += coins;
    }
    return pay_coins;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N >> C0 >> C1 >> H;
        cin >> S;
        cout << solve() << endl;
    }

    return 0;
}