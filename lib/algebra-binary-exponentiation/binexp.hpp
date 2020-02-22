#pragma once

// O (logN)
template<class T>
T binpow(T a, long long n, const T& id) {
    if (n < 0) throw;

    T ans = id;
    while (n > 0) {
        if (n & 1) {
            ans = ans * a;
        }
        a = a * a;
        n >>= 1;
    }
    return ans;
}