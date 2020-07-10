#include <bits/stdc++.h>

using namespace std;

int unique(vector<int>& A) {
    if (A.size() == 0) return 0;

    const int N = A.size();
    int i, j;
    i = j = 1;
    while (i < N && j < N) {
        if (A[j] > A[j-1]) {
            A[i] = A[j];
            i++;
        }
        j++;
    }
    return i;
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

    const int M = unique(A);
    for (int i = 0; i < M; ++i) {
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;

    return 0;
}