#include <bits/stdc++.h>

using namespace std;

// O(N logN)
vector<int> solve(const int N, vector<int> const& A, vector<bool> const& L) {
    int psum = 0;
    vector<int> unlocked;
    unlocked.reserve(N);
    for (int i = 0; i < N; ++i) {
        psum += A[i];
        if (!L[i]) unlocked.push_back(A[i]);
    }
    sort(unlocked.begin(), unlocked.end(), greater<int>());

    int i;
    vector<int> ans(A.begin(), A.end());
    for (i = N - 1; i >= 0; --i) {
        if (psum < 0) break;
        if (!L[i]) {
            int const& v = unlocked.back();
            unlocked.pop_back();
            ans[i] = v;
        }
        psum -= ans[i];
    }
    for (; i >= 0; --i) {
        if (L[i]) continue;
        ans[i] = unlocked.back();
        unlocked.pop_back();
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T, N;
    vector<int> A;
    vector<bool> L;

    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N;
        A.assign(N, 0);
        L.assign(N, false);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < N; ++i) {
            int b;
            cin >> b;
            L[i] = b == 1;
        }
        auto ans = solve(N, A, L);
        for (int i = 0; i < N; ++i) {
            if (i > 0) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }

    return 0;
}