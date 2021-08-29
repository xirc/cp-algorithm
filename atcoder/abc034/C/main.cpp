#include <bits/stdc++.h>

template <uint64_t MOD = 1000000007>
class CombinationBasic {
    size_t N;
    std::vector<uint64_t> factorial, inverse, factorial_inverse;

public:
    // Time: O(N)
    CombinationBasic(
        size_t const N = 10000000
    )
    {
        build(N);
    }
    // Time: O(N)
    void build(size_t const N) {
        this->N = N;
        factorial.assign(N + 1, 0);
        factorial_inverse.assign(N + 1, 0);
        inverse.assign(N + 1, 0);
        factorial[0] = factorial[1] = 1;
        factorial_inverse[0] = factorial_inverse[1] = 1;
        inverse[0] = 0;
        inverse[1] = 1;
        for (size_t i = 2; i <= N; ++i) {
            factorial[i] = factorial[i-1] * i % MOD;
            inverse[i] = MOD - inverse[MOD % i] * (MOD / i) % MOD;
            factorial_inverse[i] = factorial_inverse[i-1] * inverse[i] % MOD;
        }
    }
    // nCk
    // n = [0,N], k = [0,n]
    // Time: O(1)
    uint64_t C(size_t const n, size_t const k) const {
        if (k > n) throw std::out_of_range("k");
        if (n > N) throw std::out_of_range("n");
        return factorial[n] * (factorial_inverse[k] * factorial_inverse[n - k] % MOD) % MOD;
    }
    // nPk
    // P(n,k) = n! / (n-k)!
    // n = [0,N], k = [0,n]
    // Time: O(1)
    uint64_t P(size_t const n, size_t const k) const {
        if (k > n) throw std::out_of_range("k");
        if (n > N) throw std::out_of_range("n");
        return factorial[n] * factorial_inverse[n-k] % MOD;
    }
    // nHk
    // H(n,k) = C(n+k-1,k)
    // n = [0,N-k+1], k = [0,N]
    // Time: O(1)
    uint64_t H(size_t const n, size_t const k) const {
        if (n == 0 && k == 0) return 1;
        return C(n+k-1, k);
    }
    // Time: O(1)
    size_t size() const {
        return N;
    }
};


using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int W, H;
    cin >> W >> H;

    int N = W - 1 + H - 1;
    int K = W - 1;
    CombinationBasic<> solver(N+1);
    cout << solver.C(N, K) << endl;

    return 0;
}