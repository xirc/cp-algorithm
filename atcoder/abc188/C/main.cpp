#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, M;
vector<int> A;

array<int,2> solve(int tl, int tr) {
    if (tr - tl == 2) {
        if (A[tl] < A[tl+1]) return { tl, tl+1 };
        else return { tl+1, tl };
    }
    int tm = (tl + tr) >> 1;
    auto lhs = solve(tl, tm);
    auto rhs = solve(tm, tr);
    int l = lhs[1], r = rhs[1];
    if (A[l] < A[r]) return { l, r };
    else return { r, l };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    M = 1 << N;
    A.assign(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> A[i];
    }
    int ans = solve(0, M)[0] + 1;
    cout << ans << endl;

    return 0;
}