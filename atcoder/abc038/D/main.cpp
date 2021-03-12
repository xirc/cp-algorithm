#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<array<int,2>> whs;

const int M = 1e6;
vector<int> segtree;
void build() {
    segtree.assign(4 * M, 0);
}
int query(int l, int v = 0, int tl = 0, int tr = M) {
    if (tr - tl <= 0) return 0;
    if (tl >= l) return segtree[v];
    if (tr <= l) return 0;
    int tm = (tl + tr) / 2;
    int lhs = query(l, v * 2 + 1, tl, tm);
    int rhs = query(l, v * 2 + 2, tm, tr);
    return max(lhs, rhs);
}
void update(int i, int value, int v = 0, int tl = 0, int tr = M) {
    if (tr - tl <= 0) return;
    if (tr - tl == 1) {
        segtree[v] = max(segtree[v], value);
        return;
    }
    int tm = (tl + tr) / 2;
    if (i < tm) {
        update(i, value, v * 2 + 1, tl, tm);
    } else {
        update(i, value, v * 2 + 2, tm, tr);
    }
    segtree[v] = max(segtree[v * 2 + 1], segtree[v * 2 + 2]);
}

int solve() {
    sort(whs.begin(), whs.end());
    whs.erase(unique(whs.begin(), whs.end()), whs.end());
    reverse(whs.begin(), whs.end());
    N = whs.size();

    build();
    for (int i = 0; i < N; ) {
        int w = whs[i][0];
        vector<array<int,2>> updates;
        while (i < N && whs[i][0] == w) {
            int h = whs[i][1];
            int maxi = query(h + 1);
            updates.push_back({ h, maxi + 1 });
            ++i;
        }
        for (auto const& up : updates) {
            int h = up[0], value = up[1];
            update(h, value);
        }
    }
    return query(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    whs.assign(N, { 0, 0 });
    for (auto &wh : whs) {
        cin >> wh[0] >> wh[1];
    }
    cout << solve() << endl;

    return 0;
}