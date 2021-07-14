#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K, M;
    vector<int> A;

    cin >> N >> K >> M;
    A.assign(N - 1, 0);
    for (auto &a : A) cin >> a;

    int sum = accumulate(A.begin(), A.end(), 0, plus<int>());
    int s = max(M * N - sum, 0);
    if (s > K) s = -1;
    cout << s << endl;

    return 0;
}