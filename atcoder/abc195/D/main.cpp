#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, M;
vector<array<int,2>> VW;
vector<int> X;

void build() {
    sort(VW.begin(), VW.end());
    reverse(VW.begin(), VW.end());
}

// [L,R), 0-indexed
int solve(int L, int R) {
    multiset<int> xs;
    for (int i = 0; i < M; ++i) {
        if (i < L || i >= R) {
            xs.insert(X[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        auto v = VW[i][0], w = VW[i][1];
        auto it = xs.lower_bound(w);
        if (it == xs.end()) continue;
        ans += v;
        xs.erase(it);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int Q;
    cin >> N >> M >> Q;
    VW.assign(N, { 0, 0 });
    for (int i = 0; i < N; ++i) {
        cin >> VW[i][1] >> VW[i][0];
    }
    X.assign(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> X[i];
    }

    build();
    for (int i = 0; i < Q; ++i) {
        int L, R;
        cin >> L >> R;
        --L;
        cout << solve(L, R) << endl;
    }

    return 0;
}