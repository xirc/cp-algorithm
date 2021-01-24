#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int N;
vector<int> A;

int solve() {
    int ans = 0;
    for (int l = 0; l < N; ++l) {
        int mini = A[l];
        for (int r = l; r < N; ++r) {
            mini = min(mini, A[r]);
            ans = max(ans, (r - l + 1) * mini);
        }
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
    cout << solve() << endl;

    return 0;
}