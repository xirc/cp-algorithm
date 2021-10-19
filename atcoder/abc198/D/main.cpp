#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

vector<ll> solve(string const& s1, string const& s2, string const& s3) {
    vector<ll> const unsolvable = {};

    set<char> cs;
    for (auto c : s1) cs.insert(c);
    for (auto c : s2) cs.insert(c);
    for (auto c : s3) cs.insert(c);
    if (cs.size() > 10) {
        return unsolvable;
    }

    vector<char> const xs(cs.begin(), cs.end());
    int const n = xs.size();
    vector<bool> used(10, false);
    vector<int> decode_map(26, -1);
    auto const decode = [&](string const& s) {
        ll value = 0;
        for (auto c : s) {
            value *= 10;
            value += decode_map[c-'a'];
        }
        return value;
    };
    auto const check = [&]() -> bool {
        return decode(s1) + decode(s2) == decode(s3);
    };
    function<bool(int)> const solve = [&](int i) {
        if (i == n) {
            return check();
        }
        bool const not_zero =
            xs[i] == s1[0] || xs[i] == s2[0] || xs[i] == s3[0];
        for (int m = 0; m < 10; ++m) {
            if (m == 0 && not_zero) continue;
            if (used[m]) continue;
            used[m] = true;
            decode_map[xs[i]-'a'] = m;
            auto pass = solve(i + 1);
            if (pass) return true;
            used[m] = false;
        }
        return false;
    };
    auto const pass = solve(0);
    if (!pass) {
        return unsolvable;
    }
    return { decode(s1), decode(s2), decode(s3) };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    auto const ans = solve(s1, s2, s3);
    if (ans.size() < 3) {
        cout << "UNSOLVABLE" << endl;
    } else {
        cout << ans[0] << endl;
        cout << ans[1] << endl;
        cout << ans[2] << endl;
    }

    return 0;
}