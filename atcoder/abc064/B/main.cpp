#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
vector<int> A;

int solve() {
    sort(A.begin(), A.end());
    int ans = 0;
    for (int i = 1; i < N; ++i) {
        ans += A[i] - A[i-1];
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