#include <bits/stdc++.h>

class CombinationPascal {
    size_t N;
    uint64_t MOD;
    std::vector<std::vector<uint64_t>> C;

public:
    // Time: O(N^2)
    CombinationPascal(
        size_t const N = 1000,
        uint64_t const MOD = std::numeric_limits<uint64_t>::max()
    )
    {
        build(N, MOD);
    }
    // Time: O(N^2)
    void build(size_t const N, uint64_t const MOD) {
        this->N = N;
        this->MOD = MOD;
        C.assign(N, std::vector<uint64_t>(N, 0));
        C[0][0] = 1;
        for (size_t n = 1; n < N; ++n) {
            C[n][0] = 1;
            for (size_t k = 1; k < N; ++k) {
                C[n][k] = (C[n-1][k-1] + C[n-1][k]) % MOD;
            }
        }
    }
    // nCk
    // n = [0,N), k = [0,n]
    // Time: O(1)
    uint64_t operator()(size_t const n, size_t const k) const {
        if (k > n) throw std::out_of_range("k");
        if (n >= N) throw std::out_of_range("n");
        return C[n][k];
    }
    // Time: O(1)
    size_t size() const {
        return N;
    }
};

using namespace std;
using ll = int64_t;

int N, A, B;
vector<ll> vs;

pair<double,ll> solve() {
    CombinationPascal comb(N+1);

    map<ll,int,greater<ll>> mp;
    for (int i = 0; i < N; ++i) {
        mp[vs[i]]++;
    }

    ll sum = 0;
    int acc = 0;
    for (auto e : mp) {
        auto v = e.first;
        auto c = e.second;
        if (acc + c < A) {
            acc += c;
            sum += ll(v) * c;
            continue;
        } else if (acc == 0) {
            assert(sum == 0);
            ll ans = 0;
            for (int k = A; k <= min(c,B); ++k) {
                ans += comb(c, k);
            }
            return make_pair(v, ans);
        } else {
            int r = A - acc;
            sum += ll(v) * r;
            return make_pair(double(sum) / A, comb(c,r));
        }
    }
    throw;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> A >> B;
    vs.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> vs[i];
    }

    double avg;
    ll com;
    tie(avg,com) = solve();
    cout << fixed << setprecision(6) << avg << endl;
    cout << com << endl;

    return 0;
}