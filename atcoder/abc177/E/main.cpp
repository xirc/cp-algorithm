#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

bool is_pairwise_coprime(vector<int> const& A) {
    int const N = 2e6;
    vector<int> count(N, 0);
    vector<bool> is_primes(N, true);
    is_primes[0] = is_primes[1] = false;
    for (auto x : A) {
        count[x]++;
    }

    for (int p = 2; p < N; ++p) {
        if (!is_primes[p]) continue;
        int xP = count[p];
        for (int q = 2 * p; q < N; q += p) {
            is_primes[q] = false;
            xP += count[q];
        }
        if (xP > 1) return false;
    }
    return true;
}

int gcd(int a, int b) {
    while (b > 0) {
        int c = a % b;
        a = b; b = c;
    }
    return a;
}

int gcd(vector<int> const& A) {
    int g = 0;
    for (auto n : A) {
        g = gcd(g, n);
    }
    return g;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> A;

    cin >> N;
    A.assign(N, 0);
    for (auto &x : A) cin >> x;

    if (is_pairwise_coprime(A)) {
        cout << "pairwise coprime" << endl;
    } else if (gcd(A) == 1) {
        cout << "setwise coprime" << endl;
    } else {
        cout << "not coprime" << endl;
    }

    return 0;
}