#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    N %= 30;
    vector<int> A = { 1, 2, 3, 4, 5, 6 };
    for (int i = 0; i < N; ++i) {
        int a = (i % 5), b = (i % 5) + 1;
        swap(A[a], A[b]);
    }
    for (int i = 0; i < 6; ++i) {
        cout << A[i];
    }
    cout << endl;

    return 0;
}