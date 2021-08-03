#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (auto &a :A) cin >> a;

    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    int T = accumulate(A.begin(), A.end(), 0, plus<int>());
    auto pass = all_of(A.begin(), A.begin() + M, [&](int a) {
        return a * 4 * M >= T;
    });
    cout << (pass ? "Yes" : "No") << endl;

    return 0;
}