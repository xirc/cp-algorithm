#include <bits/stdc++.h>

using namespace std;

// Time: O(N logN)
// Memory: O(N logN)
long long swap_count(vector<int>& A) {
    const int N = A.size();
    const int M = N / 2;

    if (N <= 1) return 0;

    long long count = 0;
    vector<int> B(A.begin(), A.begin() + M);
    vector<int> C(A.begin() + M, A.end());
    count += swap_count(B);
    count += swap_count(C);
    for (int i = 0, j = 0, k = 0; i < N; ++i) {
        if (k == C.size()) A[i] = B[j++];
        else if (j == B.size()) A[i] = C[k++];
        else if (B[j] <= C[k]) A[i] = B[j++];
        else {
            count += M - j;
            A[i] = C[k++];
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N;
    vector<int> A;
    
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N;
        A.assign(N, 0);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        const long long K = (long long)N * (N - 1) / 2 - 1;
        auto count = swap_count(A);
        if (count <= K) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}