#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;

    cin >> N >> K;
    int C = K;
    for (int i = 1; i < N; ++i) {
        C *= K - 1;
    }
    cout << C << endl;

    return 0;
}