#include <bits/stdc++.h>

using namespace std;

int N, M, X;
vector<int> A;

int solve() {
    int ans = 1000;
    ans = min(ans, accumulate(A.begin(), A.begin() + X, 0, plus<int>()));
    ans = min(ans, accumulate(A.begin() + X, A.end(), 0, plus<int>()));
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> X;
    A.assign(N + 1, 0);
    for (int i = 0; i < M; ++i) {
        int ai;
        cin >> ai;
        A[ai] = 1;
    }
    cout << solve() << endl;


    return 0;
}