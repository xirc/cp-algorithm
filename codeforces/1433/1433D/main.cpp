#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solve(int N, vector<int> const& A) {
    auto r = A[0];
    bool sameAll = all_of(A.begin(), A.end(), [&](auto a) { return a == r; });
    if (sameAll) return {};

    vector<vector<int>> ans;
    for (int i = 1; i < N; ++i) {
        if (r != A[i]) {
            ans.push_back({ 0, i });
        } else {
            for (int j = 1; j < N; ++j) {
                if (A[i] != A[j]) {
                    ans.push_back({ i, j });
                    break;
                }
            }
        }
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
        A.assign(N, 0);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        auto ans = solve(N, A);
        if (ans.size() == 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (auto &e : ans) {
                cout << (e[0] + 1) << " " << (e[1] + 1) << endl;
            }
        }
    }

    return 0;
}