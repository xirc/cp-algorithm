#include <bits/stdc++.h>

using namespace std;

const int M = 1000;
vector<int> nearly_primes;

void build() {
    vector<int> primes;
    primes.reserve(M);
    vector<bool> is_prime(M, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int p = 2; p * p < M; ++p) {
        if (!is_prime[p]) continue;
        primes.push_back(p);
        for (int np = p * 2; np < M; np += p) {
            is_prime[np] = false;
        }
    }

    nearly_primes.clear();
    nearly_primes.reserve(M);
    for (int i = 0; i < primes.size(); ++i) {
        for (int j = i + 1; j < primes.size(); ++j) {
            nearly_primes.push_back(primes[i] * primes[j]);
        }
    }
    sort(nearly_primes.begin(), nearly_primes.end());
}

vector<int> solve(const int N) {
    for (int i = 0; i < nearly_primes.size(); ++i) {
        for (int j = i + 1; j < nearly_primes.size(); ++j) {
            for (int k = j + 1; k < nearly_primes.size(); ++k) {
                int Al = N -
                    (nearly_primes[i] +
                    nearly_primes[j] +
                    nearly_primes[k]);
                if (Al > 0 &&
                    Al != nearly_primes[i] &&
                    Al != nearly_primes[j] &&
                    Al != nearly_primes[k]
                    )
                {
                    return { nearly_primes[i], nearly_primes[j], nearly_primes[k], Al };
                }
            }
        }
    }
    return {};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    build();

    int T, N;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N;
        auto ans = solve(N);
        if (ans.size() != 4) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < ans.size(); ++i) {
                if (i > 0) cout << " ";
                cout << ans[i];
            }
            cout << endl;
        }
    }

    return 0;
}