#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

vector<int> solve(int N, int X, int Y) {
    vector<int> ans(N - 1, 0);
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int d = min({
                j - i,
                abs(X - i) + 1 + abs(Y - j),
                abs(Y - i) + 1 + abs(X - j)
            });
            ans[d-1]++;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, X, Y;
    cin >> N >> X >> Y;
    --X, --Y;
    auto ans = solve(N, X, Y);
    for (auto p : ans) {
        cout << p << endl;
    }

    return 0;
}