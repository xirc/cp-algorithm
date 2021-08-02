#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int K, N;
    vector<int> A;

    cin >> K >> N;
    A.assign(N, 0);
    for (auto &a : A) cin >> a;

    sort(A.begin(), A.end());
    A.push_back(A[0] + K);

    int maxi = A[1] - A[0];
    for (int i = 2; i < (int)A.size(); ++i) {
        maxi = max(maxi, A[i] - A[i-1]);
    }
    int D = K - maxi;
    cout << D << endl;

    return 0;
}