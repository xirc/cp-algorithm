#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;

int solve() {
    int ans = 0;
    for(int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            ans = max(ans, abs(A[i] - A[j]));
        }
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