#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
vector<int> A;

vector<vector<int>> solve() {
    int r = 0, q = 0;
    int maxi = A[0], mini = A[0];
    for (int i = 1; i < N; ++i) {
        if (maxi < A[i]) {
            maxi = A[i];
            r = i;
        }
        if (mini > A[i]) {
            mini = A[i];
            q = i;
        }
    }

    // Do nothing
    if (maxi == mini) {
        return {};
    }

    vector<vector<int>> ans;
    if (abs(maxi) >= abs(mini)) {
        for (int i = 0; i < N; ++i) {
            if (i == r) continue;
            A[i] += maxi;
            ans.push_back({ r, i });
        }
        for (int i = 1; i < N; ++i) {
            if (A[i] >= A[i-1]) continue;
            A[i] += A[i-1];
            ans.push_back({ i - 1, i });
        }
    } else {
        for (int i = 0; i < N; ++i) {
            if (i == q) continue;
            A[i] += mini;
            ans.push_back({ q, i });
        }
        for (int i = N - 2; i >= 0; --i) {
            if (A[i] <= A[i+1]) continue;
            A[i] += A[i+1];
            ans.push_back({i + 1, i });
        }
    }

    assert(ans.size() <= 2 * N);
    for (int i = 1; i < N; ++i) {
        assert(A[i] >= A[i-1]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    auto ans = solve();
    cout << ans.size() << endl;
    for (auto e : ans) {
        cout << (e[0]+1) << " " << (e[1]+1) << endl;
    }

    return 0;
}