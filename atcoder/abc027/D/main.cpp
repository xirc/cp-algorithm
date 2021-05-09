#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

// O( N logN )
int solve(string const& S) {
    int const N = S.size();

    vector<int> scores;
    int score = 0;
    for (int i = N - 1; i >= 0; --i) {
        auto c = S[i];
        if (c == '+') ++score;
        else if (c == '-') --score;
        else if (c == 'M') scores.push_back(score);
        else throw;
    }

    sort(scores.begin(), scores.end());
    assert(scores.size() % 2 == 0);
    int const M = scores.size() / 2;
    int ans = 0;
    for (int i = 0; i < M; ++i) {
        ans -= scores[i];
    }
    for (int i = M; i < 2 * M; ++i) {
        ans += scores[i];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    cout << solve(S) << endl;

    return 0;
}