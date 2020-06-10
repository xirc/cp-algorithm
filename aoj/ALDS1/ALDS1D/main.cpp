#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> R;
int solve() {
    int ans = numeric_limits<int>::lowest();
    int minimum = R[0];
    for (int i = 1; i < N; ++i) {
        ans = max(ans, R[i] - minimum);
        minimum = min(minimum, R[i]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    R.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> R[i];
    }
    cout << solve() << endl;

    return 0;
}