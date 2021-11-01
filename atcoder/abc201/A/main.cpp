#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> A(3);
    cin >> A[0] >> A[1] >> A[2];
    sort(A.begin(), A.end());
    bool is_arithmetic = A[2] - A[1] == A[1] - A[0];
    cout << (is_arithmetic ? "Yes" : "No") << endl;

    return 0;
}