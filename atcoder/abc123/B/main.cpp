#include <bits/stdc++.h>

using namespace std;

int solve(int N, vector<int> & A) {
    sort(A.begin(), A.end(), [](int l, int r){
        if (l % 10 == 0) return false;
        if (r % 10 == 0) return true;
        return l % 10 < r % 10;
    });

    for (int i = 1; i < N; ++i) {
        A[i] = (A[i] + 9) / 10 * 10;
    }
    return accumulate(A.begin(), A.end(), 0, plus<int>());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> A(5);
    for (int i = 0; i < 5; ++i) {
        cin >> A[i];
    }
    cout << solve(5, A) << endl;

    return 0;
}