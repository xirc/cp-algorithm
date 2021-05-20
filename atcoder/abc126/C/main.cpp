#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;

    ff prob = 0;
    for (int i = 1; i <= N; ++i) {
        int m = 0, j = i;
        while (j < K) {
            j *= 2;
            m++;
        }
        prob += (powl(0.5, m) / N);
    }
    cout << fixed << setprecision(10) << prob << endl;

    return 0;
}