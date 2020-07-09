#include <bits/stdc++.h>

using namespace std;

void swap(vector<int>& A, int b, int e, int t) {
    int w = e - b;
    for (int i = 0; i < w; ++i) {
        swap(A[b+i], A[t+i]);
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

    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int b, e, t;
        cin >> b >> e >> t;
        swap(A, b, e, t);
    }

    for (int i = 0; i < N; ++i) {
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;

    return 0;
}