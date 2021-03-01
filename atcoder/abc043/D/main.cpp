#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

string S;

array<int,2> solve() {
    int const N = S.size();
    for (int i = 0; i + 1 < N; ++i) {
        if (S[i] == S[i+1]) return { i + 1, i + 2 };
    }
    for (int i = 0; i + 2 < N; ++i) {
        if (S[i] == S[i+2]) return { i + 1, i + 3 };
    }
    return { -1, -1 };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> S;
    auto ans = solve();
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}