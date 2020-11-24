#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> A(3);
    cin >> A[0] >> A[1] >> A[2];
    sort(A.begin(), A.end());
    int ans = numeric_limits<int>::max();
    do {
        ans = min(ans, abs(A[1]-A[0]) + abs(A[2]-A[1]));
    } while (next_permutation(A.begin(), A.end()));
    cout << ans << endl;

    return 0;
}