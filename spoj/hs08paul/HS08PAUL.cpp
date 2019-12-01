// https://www.spoj.com/problems/HS08PAUL/

#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

// is_prime[i] is whether 'i' is prime or not
vector<bool> build_prime_table(int N) {
    const int SQRT_N = sqrt(N);

    vector<bool> is_prime(N, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int p = 2; p < SQRT_N; ++p) {
        if (!is_prime[p]) {
            continue;
        }
        for (int j = p * p; j < N; j += p) {
            is_prime[j] = false;
        }
    }

    return is_prime;
}

// has_sqrti[i] is whether 'i' has 'sqrt(i)' value which is an integer.
vector<bool> build_sqrti_table(int N) {
    vector<bool> has_sqrti(N, false);
    const int SQRT_N = sqrt(N);

    for (int i = 0; i < SQRT_N; ++i) {
        has_sqrti[i * i] = true;
    }

    return has_sqrti;
}

// count[i] is the number of primes not larger than n which are of the form (x**2 + y**4)
vector<int> solve(int N, vector<bool>& is_prime, vector<bool>& has_sqrt) {
    vector<int> count(N);

    count[0] = 0;
    for (int i = 1; i < N; ++i) {
        count[i] = count[i-1];
        if (!is_prime[i]){
            continue;
        }
        for (int y = 1; y * y * y * y < i; ++y) {
            int x = i - y * y * y * y;
            if (has_sqrt[x]) {
                count[i]++;
                break;
            }
        }
    }

    return count;
}

int main() {
    const int N = 10000000 + 1;
    auto is_prime = build_prime_table(N);
    auto has_sqrti = build_sqrti_table(N);
    auto count = solve(N, is_prime, has_sqrti);

    int T, query;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        scanf("%d", &query);
        printf("%d\n", count[query]);
    }

    return 0;
}