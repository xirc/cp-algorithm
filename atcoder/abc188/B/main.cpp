#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (auto &a : A) cin >> a;
    for (auto &b : B) cin >> b;

    ll ip = 0;
    for (int i = 0; i < N; ++i) {
        ip += A[i] * B[i];
    }
    bool ans = ip == 0;
    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}