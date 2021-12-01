#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll dec(string const& N, int K) {
    ll m = 0;
    for (char x : N) {
        m *= K;
        m += (x - '0');
    }
    return m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int K;
    string A, B;
    cin >> K >> A >> B;

    ll C = dec(A, K) * dec(B, K);
    cout << C << endl;

    return 0;
}