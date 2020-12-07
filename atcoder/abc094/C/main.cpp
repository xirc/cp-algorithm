#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> X;

vector<int> solve() {
    vector<int> ans;
    vector<int> Y = X;
    sort(Y.begin(), Y.end());
    auto ml = Y[(N-1)/2], mr = Y[N/2];
    for (int i = 0; i < N; ++i) {
        if (X[i] >= mr) {
            ans.push_back(ml);
        } else {
            ans.push_back(mr);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    X.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }
    auto ans = solve();
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}