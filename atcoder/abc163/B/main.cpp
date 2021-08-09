#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;
    vector<int> A;

    cin >> N >> M;
    A.assign(M, 0);
    for (auto &a: A) cin >> a;

    int L = accumulate(A.begin(), A.end(), 0, plus<int>());
    int R = N - L;
    cout << (R < 0 ? -1 : R) << endl;

    return 0;
}