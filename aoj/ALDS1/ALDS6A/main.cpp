#include <bits/stdc++.h>

using namespace std;

void counting_sort(const vector<int>& A, vector<int>& B, int K) {
    vector<int> C(K+1, 0);
    for (int i = 0; i < A.size(); ++i) {
        C[A[i]]++;
    }
    for (int i = 1; i < K; ++i) {
        C[i] += C[i-1];
    }
    for (int i = A.size() - 1; i >= 0; --i) {
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    counting_sort(A, B, 10000);
    for (int i = 0; i < N; ++i) {
        if (i > 0) cout << " ";
        cout << B[i];
    }
    cout << endl;

    return 0;
}