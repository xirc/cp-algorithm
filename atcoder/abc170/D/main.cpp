#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> A;

    cin >> N;
    A.assign(N, 0);
    for (auto &a : A) cin >> a;

    int const M = 1e6+1;
    vector<int> count(M, 0);
    vector<bool> pass(M, true);
    for (auto a : A) {
        count[a]++;
    }
    for (int a = 1; a < M; ++a) {
        if (count[a] == 0) continue;
        if (count[a] > 1) pass[a] = false;
        for (int b = 2 * a; b < M; b += a) {
            pass[b] = false;
        }
    }

    int ans = 0;
    for (auto a : A) {
        if (pass[a]) ++ans;
    }
    cout << ans << endl;

    return 0;
}