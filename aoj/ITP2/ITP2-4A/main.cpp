#include <bits/stdc++.h>

using namespace std;

// O(N)
// [b,e)
// Don't use std::reverse
void reverse(vector<int>& A, int b, int e) {
    const int W = (e - b) / 2;
    for (int i = 0; i < W; ++i) {
        swap(A[b+i], A[e-1-i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, Q;
    vector<int> A;

    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // O(NQ)
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int b, e;
        cin >> b >> e;
        reverse(A, b, e);
    }

    for (int i = 0; i < N; ++i) {
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;

    return 0;
}