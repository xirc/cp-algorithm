#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> A(3);
    cin >> A[0] >> A[1] >> A[2];
    sort(A.begin(), A.end());
    cout << A[1] << endl;

    return 0;
}