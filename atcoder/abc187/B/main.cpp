#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> X, Y;

int solve() {
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int dx = X[j] - X[i];
            int dy = Y[j] - Y[i];
            if (abs(dy) <= abs(dx)) {
                ++ans;
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    X.assign(N,0);
    Y.assign(N,0);
    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> Y[i];
    }
    cout << solve() << endl;

    return 0;
}