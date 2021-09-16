#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;
    vector<int> A;

    cin >> N;
    M = 1 << N;
    A.assign(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> A[i];
    }

    M /= 2;
    auto l = distance(A.begin(), max_element(A.begin(), A.begin() + M));
    auto r = distance(A.begin(), max_element(A.begin() + M, A.end()));
    int ans = (A[l] < A[r]) ? l : r;
    cout << (ans+1) << endl;

    return 0;
}