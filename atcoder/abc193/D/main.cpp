#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int score(vector<int> const& cs) {
    int s = 0;
    for (int i = 0; i < 10; ++i) {
        int cc = i;
        for (int j = 0; j < cs[i]; ++j) {
            cc *= 10;
        }
        s += cc;
    }
    return s;
}

ff solve(int K, string S, string T) {
    ff ans = 0;
    int N = 9 * K;
    vector<int> cards(10, K);
    vector<int> ss(10, 0), ts(10, 0);
    cards[0] = 0;
    for (int i = 0; i < 4; ++i) {
        N -= 2;
        cards[S[i] - '0']--;
        cards[T[i] - '0']--;
        ss[S[i]-'0']++;
        ts[T[i]-'0']++;
    }
    for (int i = 1; i < 10; ++i) {
        if (cards[i] == 0) continue;
        ff pi = cards[i] / ff(N);
        --N;
        cards[i]--;
        ss[i]++;
        int si = score(ss);
        for (int j = 1; j < 10; ++j) {
            if (cards[j] == 0) continue;
            ff pj = cards[j] / ff(N);
            ts[j]++;
            int sj = score(ts);
            if (si > sj) {
                ans += pi * pj;
            }
            ts[j]--;
        }
        ++N;
        cards[i]++;
        ss[i]--;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int K;
    string S, T;
    cin >> K >> S >> T;
    cout << fixed << setprecision(6) << solve(K, S, T) << endl;

    return 0;
}