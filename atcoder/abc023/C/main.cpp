#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int R, C, K;
int N;
vector<int> rs, cs;

ll solve() {
    vector<vector<int>> G(R, vector<int>());
    vector<int> candies_by_row(R, 0);
    vector<int> candies_by_col(C, 0);
    for (int i = 0; i < N; ++i) {
        ++candies_by_row[rs[i]];
        ++candies_by_col[cs[i]];
        G[rs[i]].push_back(cs[i]);
    }

    map<int,int> cols_by_candies;
    for (int c = 0; c < C; ++c) {
        ++cols_by_candies[candies_by_col[c]];
    }

    ll cells = 0;
    for (int r = 0; r < R; ++r) {
        for (auto c : G[r]) {
            int candies = candies_by_col[c];
            --cols_by_candies[candies];
            ++cols_by_candies[candies-1];
        }

        cells += cols_by_candies[K - candies_by_row[r]];

        for (auto c : G[r]) {
            int candies = candies_by_col[c];
            ++cols_by_candies[candies];
            --cols_by_candies[candies-1];
        }
    }
    return cells;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> R >> C >> K;
    cin >> N;
    rs.assign(N, 0);
    cs.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> rs[i] >> cs[i];
        --rs[i], --cs[i];
    }
    cout << solve() << endl;

    return 0;
}