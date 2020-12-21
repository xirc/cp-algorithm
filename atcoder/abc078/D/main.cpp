#include <bits/stdc++.h>

using namespace std;

int N, Z, W;
vector<int> A;

int solve() {
    int V = A[N-1];
    int ans = abs(V - W);
    if (N > 1) {
        int U = A[N-2];
        ans = max(ans, abs(U - V));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> Z >> W;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout << solve() << endl;

    return 0;
}