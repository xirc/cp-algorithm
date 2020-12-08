#include <bits/stdc++.h>

using namespace std;

int N, D, X;
vector<int> A;

int solve() {
    int ans = X;
    for (int i = 0; i < N; ++i) {
        auto ai = A[i];
        for (int j = 1; j <= D; j += ai) {
            ans += 1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> D >> X;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout << solve() << endl;

    return 0;
}