#include <bits/stdc++.h>

template<class T>
inline T binexp(
    const T& a,
    unsigned long long n,
    const T& id,
    const std::function<T(const T&, const T&)> op = std::multiplies<T>()
) {
    auto ans = id;
    auto p = a;
    while (n > 0) {
        if (n & 1) {
            ans = op(ans, p);
        }
        p = op(p, p);
        n >>= 1;
    }
    return ans;
}


using namespace std;

const long long M = 1e9+7;
long long powmod(long long b, long long e) {
    return binexp<long long>(b, e, 1, [&](auto const& lhs, auto const& rhs){
        return (lhs * rhs) % M;
    });
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long m, n;
    cin >> m >> n;
    auto ans = powmod(m, n);
    cout << ans << endl;

    return 0;
}