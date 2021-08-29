#include <bits/stdc++.h>

template<uint64_t MOD = std::numeric_limits<uint64_t>::max()>
class CombinationPascal {
    size_t N;
    std::vector<std::vector<uint64_t>> comb;

public:
    // Time: O(N^2)
    CombinationPascal(
        size_t const N = 1000
    )
    {
        build(N);
    }
    // Time: O(N^2)
    void build(size_t const N) {
        this->N = N;
        comb.assign(N + 1, std::vector<uint64_t>(N + 1, 0));
        comb[0][0] = 1;
        for (size_t n = 1; n <= N; ++n) {
            comb[n][0] = 1;
            for (size_t k = 1; k <= N; ++k) {
                comb[n][k] = (comb[n-1][k-1] + comb[n-1][k]) % MOD;
            }
        }
    }
    // nCk
    // n = [0,N], k = [0,n]
    // Time: O(1)
    uint64_t C(size_t const n, size_t const k) const {
        if (k > n) throw std::out_of_range("k");
        if (n > N) throw std::out_of_range("n");
        return comb[n][k];
    }
    // nHk
    // H(n,k) = C(n+k-1,k)
    // n = [0,N-k+1], k = [0,N]
    // Time: O(1)
    uint64_t H(size_t const n, size_t const k) const {
        if (n == 0 && k == 0) return 1;
        return C(n+k-1,k);
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
    CombinationPascal<> solver(N+1);

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
                ans += solver.C(c, k);
            }
            return make_pair(v, ans);
        } else {
            int r = A - acc;
            sum += ll(v) * r;
            return make_pair(double(sum) / A, solver.C(c,r));
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