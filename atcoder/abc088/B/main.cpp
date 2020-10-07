#include <bits/stdc++.h>

using namespace std;

int solve(int N, vector<int>& A) {
    sort(A.begin(), A.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            ans += A[i];
        } else {
            ans -= A[i];
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> A;

    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout << solve(N, A) << endl;

    return 0;
}