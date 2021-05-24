#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

vector<int> D;
void solve(vector<int> const& A, int from, int until, int depth) {
    if (from >= until) return;
    auto i = distance(A.begin(), max_element(A.begin() + from, A.begin() + until));
    D[i] = depth;
    solve(A, from, i, depth + 1);
    solve(A, i+1, until, depth + 1);
}

// O(N**2)
vector<int> solve(int N, vector<int> const& A) {
    D.assign(N, 0);
    solve(A, 0, N, 0);
    return D;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        int N;
        vector<int> A;
        cin >> N;
        A.assign(N, 0);
        for (auto &a : A) cin >> a;
        auto ans = solve(N, A);
        for (int i = 0; i < N; ++i) {
            if (i > 0) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }

    return 0;
}