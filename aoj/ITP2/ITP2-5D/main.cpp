#include <bits/stdc++.h>

using namespace std;

void dump(const vector<int>& A) {
    for (int i = 0; i < A.size(); ++i) {
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    vector<int> A(N, 0);
    for (int i = 0; i < N; ++i) {
        A[i] = i + 1;
    }

    // O(N^2)
    do {
        dump(A);
    } while (next_permutation(A.begin(), A.end()));

    return 0;
}