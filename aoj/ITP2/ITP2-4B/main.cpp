#include <bits/stdc++.h>

using namespace std;

// O(N)
// rotate [b,e)
// Don't use std:rotate for learning
void rotate(vector<int>& A, int b, int m, int e) {
    reverse(A.begin() + b, A.begin() + m);
    reverse(A.begin() + m, A.begin() + e);
    reverse(A.begin() + b, A.begin() + e);
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

    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int b, m, e;
        cin >> b >> m >> e;
        rotate(A, b, m, e);
    }

    for (int i = 0; i < N; ++i) {
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;

    return 0;
}