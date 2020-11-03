#include <bits/stdc++.h>

using namespace std;

int solve(int a, int b, string const& S) {
    vector<int> vs;

    int i = 0;
    while (i < S.size() && S[i] == '0') ++i;
    bool noMine = true;
    int count = 0;
    for (; i < S.size(); ++i) {
        if (S[i] == '0') {
            ++count;
        } else if (S[i] == '1') {
            noMine = false;
            if (count > 0) {
                vs.push_back(count);
                count = 0;
            }
        } else throw;
    }

    if (noMine) return 0;

    int coins = 0;
    int K = vs.size() + 1;
    for (int i = 0; i < vs.size(); ++i) {
        if (vs[i] * b < a) {
            --K;
            coins += vs[i] * b;
        }
    }
    return coins + a * K;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, a, b;
    string S;

    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> a >> b >> S;
        cout << solve(a, b, S) << endl;
    }

    return 0;
}