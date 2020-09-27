#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& A) {
    const int N = A.size();

    auto B = A;
    sort(B.begin(), B.end());

    int j = N - 1;
    for (int i = 0; i < N; i+=2) {
        A[i] = B[j];
        --j;
    }
    for (int i = 1; i < N; i+=2) {
        A[i] = B[j];
        --j;
    }

    // Answer exists in any case.
    return (N - 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> A;
    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout  << solve(A) << endl;
    for (int i = 0; i < N; ++i) {
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;

    return 0;
}