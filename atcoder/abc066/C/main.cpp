#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;

vector<int> solve() {
    vector<int> B(N, 0);
    int l = 0, r = N - 1;
    for (int i = 0; i < N; ++i) {
        int val = A[N-1-i];
        if ((i & 1) == 0) {
            B[l] = val;
            ++l;
        } else {
            B[r] = val;
            --r;
        }
    }
    return B;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    auto B = solve();

    for (int i = 0; i < N; ++i) {
        if (i > 0) cout << " ";
        cout << B[i];
    }
    cout << endl;

    return 0;
}