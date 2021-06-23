#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K, Q;
    cin >> N >> K >> Q;

    vector<int> C(N, 0);
    for (int i = 0; i < Q; ++i) {
        int A;
        cin >> A;
        --A;
        C[A]++;
    }
    for (int i = 0; i < N; ++i) {
        auto pass = (K - (Q - C[i]) > 0);
        cout << (pass ? "Yes" : "No") << endl;
    }

    return 0;
}