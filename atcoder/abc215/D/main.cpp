#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, M;
vector<int> A;

vector<int> solve() {
    int const K = max(M, *max_element(A.begin(), A.end()));

    set<int> S;
    for (auto v : A) S.insert(v);

    vector<bool> coprime(K+1, true);
    vector<bool> is_prime(K+1, true);
    coprime[0] = false;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= K; ++i) {
        if (!is_prime[i]) continue;
        bool exclude = S.count(i) > 0;
        for (int j = 2 * i; j <= K; j += i) {
            is_prime[j] = false;
            exclude |= S.count(j) > 0;
        }
        if (exclude) {
            for (int j = i; j <= K; j += i) {
                coprime[j] = false;
            }
        }
    }

    vector<int> ans = { 1 };
    for (int i = 2; i <= M; ++i) {
        if (coprime[i]) {
            ans.push_back(i);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    A.assign(N, 0);
    for (auto &a : A) cin >> a;

    auto ans = solve();
    cout << ans.size() << endl;
    for (auto v : ans) {
        cout << v << endl;
    }

    return 0;
}