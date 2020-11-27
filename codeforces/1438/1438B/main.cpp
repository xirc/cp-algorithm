#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;

bool solve() {
    sort(A.begin(), A.end());
    for (int i = 0; i + 1 < N; ++i) {
        if (A[i] == A[i+1]) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N;
        A.assign(N, 0);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        cout << (solve() ? "YES" : "NO") << endl;
    }

    return 0;
}
