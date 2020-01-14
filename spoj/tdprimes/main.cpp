// https://www.spoj.com/problems/TDPRIMES/

#include <cstdio>
#include <vector>

using namespace std;

const int N = 100000001;
const int K = N / 2 + 1;
// is_prime[i] = whether the number (i * 2 + 1) is prime or not
vector<bool> prime_table(K, true);

void build() {
    for (int v = 3; v * v < N; v+=2) {
        if (!prime_table[v / 2 - 1]) {
            continue;
        }
        for (int npv = v * v; npv < N; npv += 2 * v) {
            prime_table[npv / 2 - 1] = false;
        }
    }
}

inline bool is_prime(int value) {
    if (value <= 1) return false;
    if (value == 2) return true;
    if ((value & 1) == 0) return false;
    return prime_table[value / 2 - 1];
}

int main() {
    build();

    int count = 0;
    for (int i = 2; i < N; ++i) {
        if (!is_prime(i)) {
            continue;
        }
        count++;
        if (count % 100 == 1) {
            printf("%d\n", i);
        }
    }

    return 0;
}