#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int N, M, D;
vector<int> A;

vector<int> I;

vector<int> mult(vector<int> const& lhs, vector<int> const& rhs) {
    vector<int> a = I, b = I;
    for (int i = 0; i < N; ++i) {
        b[i] = lhs[a[i]];
    }
    swap(a, b);
    for (int i = 0; i < N; ++i) {
        b[i] = rhs[a[i]];
    }
    return b;
}

vector<int> binexp(vector<int> const& B, int e) {
    if (e == 0) return I;
    if (e == 1) return B;
    auto h = binexp(B, e / 2);
    auto hh = mult(h, h);
    if (e & 1) hh = mult(hh, B);
    return hh;
}

vector<int> solve() {
    vector<int> C(N), B(N);
    I.assign(N, 0);
    for (int i = 0; i < N; ++i) C[i] = I[i] = i;
    for (int i = 0; i < M; ++i) {
        swap(C[A[i]], C[A[i]+1]);
    }
    for (int i = 0; i < N; ++i) {
        B[C[i]] = i;
    }
    return binexp(B, D);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> D;
    A.assign(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> A[i];
        --A[i];
    }
    auto ans = solve();
    for (auto i : ans) {
        cout << (i + 1) << endl;
    }

    return 0;
}