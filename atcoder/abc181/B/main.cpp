#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;

    cin >> N;

    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        int A, B;
        cin >> A >> B;
        sum += ll(A + B) * (B - A + 1) / 2;
    }
    cout << sum << endl;

    return 0;
}