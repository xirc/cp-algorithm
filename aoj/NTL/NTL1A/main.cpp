#include <bits/stdc++.h>

inline std::vector<unsigned long long> prime_factorization(unsigned long long M) {
    std::vector<unsigned long long> factors;
    for (unsigned long long i = 2; i * i <= M; ++i) {
        while (M % i == 0) {
            factors.push_back(i);
            M /= i;
        }
    }
    if (M > 1) {
        factors.push_back(M);
    }
    return factors;
}

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    auto factors = prime_factorization(N);
    cout << N << ":";
    for (auto p : factors) {
        cout << " " << p;
    }
    cout << endl;

    return 0;
}