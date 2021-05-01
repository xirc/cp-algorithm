#include <bits/stdc++.h>

inline int64_t binary_search(
    std::function<bool(int64_t)> const& predicate,
    int64_t ng,
    int64_t ok
) {
    assert(!predicate(ng) && predicate(ok));
    while (abs(ok - ng) > 1) {
        auto m = (ok + ng) / 2;
        if (predicate(m)) ok = m;
        else ng = m;
    }
    return ok;
}

using namespace std;
using ll = int64_t;
using ff = long double;

int N, L, K;
vector<int> A;
vector<int> B;

bool pass(int T) {
    int c = 0;
    int x = 0;
    for (auto b : B) {
        x += b;
        if (x >= T) {
            ++c;
            x = 0;
        }
    }
    return c >= K + 1;
}

int solve() {
    B.push_back(A[0]);
    for (int i = 1; i < N; ++i) {
        B.push_back(A[i] - A[i-1]);
    }
    B.push_back(L - A[N-1]);

    int ok = 1, ng = 1e9+1;
    return binary_search(pass, ng, ok);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> L >> K;
    A.assign(N, 0);
    for (auto &ai : A) cin >> ai;
    cout << solve() << endl;

    return 0;
}