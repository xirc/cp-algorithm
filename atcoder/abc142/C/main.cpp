#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<array<int,2>> A;

    cin >> N;
    A.assign(N, { 0, 0 });
    for (int i = 0; i < N; ++i) {
        cin >> A[i][0];
        A[i][1] = i + 1;
    }
    sort(A.begin(), A.end());
    for (int i = 0; i < N; ++i) {
        if (i > 0) cout << " ";
        cout << A[i][1];
    }
    cout << endl;

    return 0;
}