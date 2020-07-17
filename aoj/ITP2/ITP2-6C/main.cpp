#include <bits/stdc++.h>

using namespace std;

// Don't use std::lower_bound for practice
int lower_bound(const vector<int>& A, int value) {
    int l = 0, r = A.size();

    while (l < r) {
        const int m = (l + r) >> 1;
        if (A[m] > value) {
            r = m;
        } else if (A[m] < value) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
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

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int k;
        cin >> k;
        int ans = lower_bound(A, k);
        cout << ans << endl;
    }

    return 0;
}