#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int N, M;
vector<vector<bool>> G;

int solve() {
    vector<int> ps(N, 0);
    for (int i = 0; i < N; ++i) {
        ps[i] = i;
    }

    int ans = 0;
    do {
        bool has_path = true;
        for (int i = 1; i < N; ++i) {
            has_path &= G[ps[i-1]][ps[i]];
        }
        if (has_path) ++ans;

    } while (next_permutation(ps.begin(), ps.end()) && ps[0] == 0);
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    G.assign(N, vector<bool>(N, false));
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a][b] = G[b][a] = true;
    }
    cout << solve() << endl;

    return 0;
}