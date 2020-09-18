#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> const& A) {
    unordered_map<int, int> count;
    for (int i = 0; i < A.size(); ++i) {
        count[A[i]]++;
    }
    const int M = 101;
    vector<int> ans;
    for (int i = 0; i <= M && ans.size() < 2; ++i) {
        if (count[i] >= 2) continue;
        if (count[i] == 1 && ans.size() == 0) {
            ans.push_back(i);
        } else if (count[i] == 0) {
            while (ans.size() < 2) ans.push_back(i);
        }
    }
    return ans[0] + ans[1];
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
        cout << solve(A) << endl;
    }

    return 0;
}