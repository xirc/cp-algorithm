#include <bits/stdc++.h>

using namespace std;

// Dont use std::set_intersection for practice
vector<int> set_intersection(const vector<int>& A, const vector<int>& B) {
    const int N = A.size(), M = B.size();
    vector<int> C;
    C.reserve(N + M);
    int i = 0, j = 0;
    while (i < N) {
        if (j == M) {
            return C;
        }
        if (A[i] < B[j]) {
            i++;
        } else if (A[i] > B[j]) {
            j++;
        } else {
            C.push_back(A[i]);
            i++, j++;
        }
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

    auto ans = set_intersection(A, B);
    for (auto v : ans) {
        cout << v << endl;
    }

    return 0;
}