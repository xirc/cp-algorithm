#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 1000000000 + 7;

ll solve(int N) {
    assert(N >= 3);

    string const ACGT = "ACGT";
    map<string, ll> cur;
    map<string, ll> next;

    for (auto c1 : ACGT) {
        for (auto c2 : ACGT) {
            for (auto c3 : ACGT) {
                vector<char> cs = { c1, c2, c3 };
                string s = string(cs.begin(), cs.end());
                if (s != "AGC" && s != "ACG" && s != "GAC") {
                    ++cur[s];
                }
            }
        }
    }

    N -= 3;
    while (N > 0) {
        for (auto p : cur) {
            auto s = p.first; auto l = p.second;
            for (auto c : ACGT) {
                string ns = s + c;
                if (ns[1] == 'A' && ns[2] == 'G' && ns[3] == 'C') continue;
                if (ns[1] == 'G' && ns[2] == 'A' && ns[3] == 'C') continue;
                if (ns[1] == 'A' && ns[2] == 'C' && ns[3] == 'G') continue;
                if (ns[0] == 'A' && ns[2] == 'G' && ns[3] == 'C') continue;
                if (ns[0] == 'A' && ns[1] == 'G' && ns[3] == 'C') continue;
                ns = ns.substr(1, 3);
                next[ns] += l;
                next[ns] %= MOD;
            }
        }
        cur = next;
        next = map<string, ll>();
        --N;
    }

    ll ans = 0;
    for (auto e : cur) {
        ans += e.second;
        ans %= MOD;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    cout << solve(N) << endl;

    return 0;
}