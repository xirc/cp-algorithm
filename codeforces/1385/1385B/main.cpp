#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int N, const vector<int>& A) {
    vector<bool> used(N+1, false);
    vector<int> ans;
    ans.reserve(N);
    for (auto v : A) {
        if (used[v]) continue;
        used[v] = true;
        ans.push_back(v);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N;
    vector<int> A;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N;
        A.assign(2 * N, 0);
        for (int i = 0; i < 2 * N; ++i) {
            cin >> A[i];
        }
        auto ans = solve(N, A);
        for (int i = 0; i < N; ++i) {
            if (i > 0) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }

    return 0;
}