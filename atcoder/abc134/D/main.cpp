#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<int> A;

vector<int> solve() {
    vector<int> B;
    B.assign(N, 0);
    for (int i = N; i >= 1; --i) {
        int count = 0;
        for (int j = i * 2; j <= N; j += i) {
            count += B[j-1];
        }
        count %= 2;
        if (A[i-1] != count) {
            B[i-1] = 1;
        }
    }
    vector<int> ans;
    for (int i = 0; i < N; ++i) {
        if (B[i] & 1) {
            ans.push_back(i + 1);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0);
    for (auto &a : A) cin >> a;
    auto ans = solve();
    cout << ans.size() << endl;
    if (ans.size() > 0) {
        for (int i = 0; i < ans.size(); ++i) {
            if (i > 0) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }

    return 0;
}