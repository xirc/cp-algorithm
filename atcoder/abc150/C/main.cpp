#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> P, Q;

    cin >> N;
    P.assign(N, 0);
    Q.assign(N, 0);
    for (auto &p : P) cin >> p;
    for (auto &q : Q) cin >> q;

    vector<int> A(N, 0);
    for (int i = 0; i < N; ++i) A[i] = i+1;

    int id = 0;
    int a = 0, b = 0;
    do {
        if (P == A) a = id;
        if (Q == A) b = id;
        ++id;
    } while (next_permutation(A.begin(), A.end()));
    cout << abs(a - b) << endl;

    return 0;
}