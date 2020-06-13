#include <bits/stdc++.h>

using namespace std;

int partition(vector<int>& A, int p, int r) {
    int x = A[r];
    int i = p;
    for (int j = p; j < r; ++j) {
        if (A[j] <= x) {
            swap(A[i], A[j]);
            i++;
        }
    }
    swap(A[i], A[r]);
    return i;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int pivot = partition(A, 0, N-1);
    for (int i = 0; i < N; ++i) {
        if (i > 0) cout << " ";
        if (i == pivot) {
            cout << "[" << A[i] << "]";
        } else {
            cout << A[i];
        }
    }
    cout << endl;

    return 0;
}