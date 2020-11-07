#include <bits/stdc++.h>

std::vector<long long> prime_factorization(long long M) {
    std::vector<long long> factors;
    long long mm = M;
    for (long long i = 2; i * i < M; ++i) {
        while (mm % i == 0) {
            factors.push_back(i);
            mm /= i;
        }
    }
    if (mm > 1) {
        factors.push_back(mm);
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