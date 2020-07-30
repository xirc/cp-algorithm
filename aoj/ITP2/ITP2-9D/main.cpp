#include <bits/stdc++.h>

using namespace std;

// Don't use std::set_symmetric_difference for practice
vector<int> set_symmetric_difference(const vector<int>& A, const vector<int>& B) {
    const int N = A.size(), M = B.size();
    vector<int> C;
    C.reserve(N + M);

    int i = 0, j = 0;
    while (i < N) {
        if (j == M) {
            copy(A.begin() + i, A.end(), back_inserter(C));
            return C;
        }
        if (A[i] < B[j]) {
            C.push_back(A[i]);
            i++;
        } else if (A[i] > B[j]) {
            C.push_back(B[j]);
            j++;
        } else {
            i++, j++;
        }
    }
    if (j < M) {
        copy(B.begin() + j, B.end(), back_inserter(C));
    }
    return C;
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

    auto ans = set_symmetric_difference(A, B);
    for (auto v : ans) {
        cout << v << endl;
    }

    return 0;
}