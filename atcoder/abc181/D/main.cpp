#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

bool solve(string const& S) {
    vector<int> count(10, 0);
    for (auto c : S) {
        int i = c - '0';
        count[i] = min(3, count[i]+1);
    }

    vector<int> xs;
    for (int i = 0; i < 10; ++i) {
        while (count[i] > 0) {
            xs.push_back(i);
            --count[i];
        }
    }

    int const M = xs.size();
    assert(M >= 1);
    if (M == 1) {
        return xs[0] % 8 == 0;
    }
    if (M == 2) {
        int s1 = xs[0] * 10 + xs[1];
        int s2 = xs[1] * 10 + xs[0];
        return (s1 % 8 == 0 || s2 % 8 == 0);
    }
    for (int i = 0; i < M; ++i) {
        for (int j = 0 ; j < M; ++j) {
            if (i == j) continue;
            for (int k = 0; k < M; ++k) {
                if (k == i || k == j) continue;
                int s = xs[i] * 100 + xs[j] * 10 + xs[k];
                if (s % 8 == 0) return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    auto ans = solve(S) ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}