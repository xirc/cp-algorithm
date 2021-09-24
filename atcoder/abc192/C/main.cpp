#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

vector<int> digits(ll x) {
    vector<int> xs;
    while (x > 0) {
        xs.push_back(x % 10);
        x /= 10;
    }
    return xs;
}

ll g1(vector<int>& digits) {
    sort(digits.begin(), digits.end(), greater<int>());
    ll y = 0;
    for (auto d : digits) {
        y = y * 10 + d;
    }
    return y;
}
ll g2(vector<int>& digits) {
    sort(digits.begin(), digits.end(), less<int>());
    ll y = 0;
    for (auto d : digits) {
        y = y * 10 + d;
    }
    return y;
}
ll f(ll x) {
    vector<int> xs = digits(x);
    return g1(xs) - g2(xs);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;

    ll a = N;
    for (int i = 0; i < K; ++i) {
        a = f(a);
    }
    cout << a << endl;

    return 0;
}