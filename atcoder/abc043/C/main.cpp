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
    for (auto &ai : A) cin >> ai;

    int ans = 200 * 200 * 100;
    for (int X = -100; X <= 100; X++) {
        int sum = 0;
        for (int ai : A) sum += (ai - X) * (ai - X);
        ans = min(ans, sum);
    }
    cout << ans << endl;

    return 0;
}