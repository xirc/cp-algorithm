#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, X;
    vector<int> A;

    cin >> N >> X;
    A.assign(N, 0);
    for (auto &a : A) cin >> a;

    for (int i = 0; i < N; ++i) {
        X -= A[i];
        X += i % 2;
    }
    auto ans = (X >= 0) ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}