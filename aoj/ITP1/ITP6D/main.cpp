#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> A(N, vector<int>(M));
    vector<int> B(M);
    vector<int> C(N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }
    for (int i = 0; i < N; ++i) {
        C[i] = 0;
        for (int j = 0; j < M; ++j) {
            C[i] += A[i][j] * B[j];
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << C[i] << endl;
    }

    return 0;
}