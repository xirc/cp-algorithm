#include <bits/stdc++.h>

using namespace std;

int compare_lexicographically(const vector<int>& A, const vector<int>& B) {
    const int N = A.size(), M = B.size();

    int i, j;
    for (i = 0, j = 0; i < N && j < M; ++i, ++j) {
        if (A[i] < B[j]) {
            return 1;
        } else if (A[i] > B[i]) {
            return -1;
        }
    }
    if (i < N) return -1;
    if (j < M) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;
    vector<int> A, B;

    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    cin >> M;
    B.assign(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }

    int cmp = compare_lexicographically(A, B);
    cout << max(cmp, 0) << endl;

    return 0;
}