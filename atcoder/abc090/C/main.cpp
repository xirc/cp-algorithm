#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll N, M;
    cin >> N >> M;
    if (N == 1 && M == 1) {
        cout << 1 << endl;
    } else if (N == 1 || M == 1) {
        cout << max(N, M) - 2 << endl;
    } else {
        cout << (N - 2) * (M - 2) << endl;
    }

    return 0;
}