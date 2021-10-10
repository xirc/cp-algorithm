#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<int> A;

int const K = 1000;
vector<int> B(K, 0);

void build() {
    for (int i = 0; i < N; ++i) {
        B[i/K] ^= A[i];
    }
}

void update(int x, int v) {
    A[x] ^= v;
    B[x/K] ^= v;
}

int query(int l, int r) {
    int ans = 0;
    int tl = (l + K - 1) / K, tr = r / K;
    if (tl > tr) {
        for (int i = l; i < r; ++i) {
            ans ^= A[i];
        }
        return ans;
    }
    for (int i = l; i < tl * K; ++i) {
        ans ^= A[i];
    }
    for (int i = tr * K; i < r; ++i) {
        ans ^= A[i];
    }
    for (int i = tl; i < tr; ++i) {
        ans ^= B[i];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int Q;
    cin >> N >> Q;
    A.assign(N, 0);
    for (auto &x : A) cin >> x;
    build();

    int T, X, Y;
    for (int q = 0; q < Q; ++q) {
        cin >> T >> X >> Y;
        if (T == 1) {
            update(X-1, Y);
        } else if (T == 2) {
            int ans = query(X-1, Y);
            cout << ans << endl;
        } else throw;
    }

    return 0;
}