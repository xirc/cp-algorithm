#include <bits/stdc++.h>

using namespace std;

// O(N+M)
bool includes(const vector<int>& A, const vector<int>& B) {
    const int N = A.size(), M = B.size();
    int i = 0, j = 0;
    while (i < N && j < M) {
        if (A[i] < B[j]) {
            i++;
        } else if (A[i] > B[j]) {
            return false;
        } else {
            j++;
        }
    }
    if (j != M) return false;
    return true;
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

    auto ans = includes(A, B) ? 1 : 0;
    cout << ans << endl;

    return 0;
}