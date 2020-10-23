#include <bits/stdc++.h>

using namespace std;

const int inf = 1e8;
int N, A, B, C;
vector<int> L;

int cost_of(bitset<8> const& S, int M) {
    if (S.count() == 0) return inf;
    int mm = 0;
    for (int i = 0; i < N; ++i) {
        if (!S[i]) continue;
        mm += L[i];
    }
    return (S.count() - 1) * 10 + abs(mm - M);
}

int solve() {
    const int SS = 1 << 8;
    const auto ALL = bitset<8>(SS-1);
    int ans = inf;
    for (int i = 1; i < SS; ++i) {
        const auto sa = bitset<8>(i);
        const int costA = cost_of(sa, A);
        if (costA >= ans) continue;
        for (int j = 1; j < SS; ++j) {
            const auto sb = bitset<8>(j) & (ALL ^ sa);
            const int costB = cost_of(sb, B);
            if (costA + costB >= ans) continue;
            for (int k = 1; k < SS; ++k) {
                const auto sc = bitset<8>(k) & (ALL ^ (sa | sb));
                const int costC = cost_of(sc, C);
                ans = min(ans, costA + costB + costC);
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> A >> B >> C;
    L.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> L[i];
    }
    cout << solve() << endl;

    return 0;
}