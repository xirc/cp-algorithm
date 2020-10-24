#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> solve(ll N) {
    vector<ll> A, B;

    A.push_back(3);
    B.push_back(5);
    while (A.back() < N) {
        A.push_back(A.back() * 3);
    }
    while (B.back() < N) {
        B.push_back(B.back() * 5);
    }

    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < B.size(); ++j) {
            if (A[i] + B[j] == N) {
                return { i + 1, j + 1 };
            }
        }
    }
    return {};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll N;

    cin >> N;
    auto ans = solve(N);
    if (ans.size() == 0) {
        cout << -1 << endl;
    } else {
        cout << ans[0] << " " << ans[1] << endl;
    }

    return 0;
}