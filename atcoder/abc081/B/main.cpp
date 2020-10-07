#include <bits/stdc++.h>

using namespace std;

int solve(int N, vector<int> const& A) {
    int ans = 100;
    for (int i = 0; i < N; ++i) {
        int count = 0;
        int v = A[i];
        while (v % 2 == 0) {
            v /= 2;
            ++count;
        }
        ans = min(ans, count);
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