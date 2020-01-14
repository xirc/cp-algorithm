// https://www.spoj.com/problems/VECTAR8/

#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> build_prime_table(const int N)
{
    const int SQRTN = sqrt(N);

    vector<bool> is_prime(N, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i < SQRTN; ++i){
        if (!is_prime[i]) {
            continue;
        }
        for (int j = i * i; j < N; j += i) {
            is_prime[j] = false;
        }
    }
    return is_prime;
}

bool has_digit0(const int value) {
    if (value % 10 == 0) {
        return true;
    }
    int newValue = value / 10;
    if (newValue == 0) {
        return false;
    }
    return has_digit0(newValue);
}

int trunc(const int value) {
    if (value < 10) {
        return 0;
    }
    int digit = (int)log10(value);
    int newValue = value % (int)pow(10, digit);
    return newValue;
}

vector<int> build_primal_fear_table(vector<bool>& is_prime)
{
    vector<int> count_table(is_prime.size(), 0);

    for (int i = 2; i < is_prime.size(); ++i) {
        count_table[i] = count_table[i - 1];
        if (has_digit0(i)) {
            continue;
        }

        bool find_not_prime = false;
        for (int v = i; v > 0; v = trunc(v)) {
            if (!is_prime[v]) {
                find_not_prime = true;
                break;
            }
        }
        if (!find_not_prime) {
            count_table[i] = count_table[i - 1] + 1;
        }
    }

    return count_table;
}

int main() {
    const int N = 1000000;

    int T, query;

    auto is_prime = build_prime_table(N);
    auto primal_fear = build_primal_fear_table(is_prime);

    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        scanf("%d", &query);
        printf("%d\n", primal_fear[query]);
    }

    return 0;
}