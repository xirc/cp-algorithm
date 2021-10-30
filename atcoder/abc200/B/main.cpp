#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll N;
    int K;
    cin >> N >> K;
    for (int i = 0; i < K; ++i) {
        if (N % 200 == 0) {
            N /= 200;
        } else {
            N = N * 1000 + 200;
        }
    }
    cout << N << endl;

    return 0;
}