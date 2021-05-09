#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

// O(N**2)
int solve(string const& S) {
    int const inf = 1e9;
    int const N = S.size();
    int const K = N * 2;
    vector<int> cur(K, inf);
    vector<int> next(K, inf);
    cur[N] = 0;

    for (auto c : S) {
        fill(next.begin(), next.end(), inf);
        for (int i = 0; i < K; ++i) {
            if (cur[i] == inf) continue;
            if (c == '+') {
                next[i] = cur[i] + (i - N);
            } else if (c == '-') {
                next[i] = cur[i] - (i - N);
            } else if (c == 'M') {
                if (i + 1 < K) {
                    if (next[i+1] != inf) {
                        next[i+1] = max(next[i+1], cur[i]);
                    } else {
                        next[i+1] = cur[i];
                    }
                }
                if (i - 1 >= 0) {
                    if (next[i-1] != inf) {
                        next[i-1] = max(next[i-1], cur[i]);
                    } else {
                        next[i-1] = cur[i];
                    }
                }
            } else throw;
        }
        swap(cur, next);
    }

    return cur[N];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    cout << solve(S) << endl;

    return 0;
}