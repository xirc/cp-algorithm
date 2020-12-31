#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> S;

int solve() {
    int const M = 10000 + 1;
    vector<bool> scores(M, false);
    scores[0] = true;
    for (int si : S) {
        for (int i = M - 1 - si; i >= 0; --i) {
            if (!scores[i]) continue;
            scores[i+si] = true;
        }
    }
    for (int i = M - 1; i >= 0; --i) {
        if (i % 10 != 0 && scores[i]) {
            return i;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    S.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }
    cout << solve() << endl;

    return 0;
}