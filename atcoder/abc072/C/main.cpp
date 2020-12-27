#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;

int solve() {
    const int M = 1e5;
    sort(A.begin(), A.end());

    int ans = 0;
    for (int x = 0; x < M; ++x) {
        auto low = lower_bound(A.begin(), A.end(), x - 1);
        auto up = upper_bound(A.begin(), A.end(), x + 1);
        ans = max(ans, (int)distance(low, up));
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