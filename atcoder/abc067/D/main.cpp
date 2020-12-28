#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> G;

// false: win W (fennec), true: win B (snuke)
bool solve() {
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> Q;
    vector<int> colors(N, 0);
    vector<bool> done(N, false);
    Q.push({ 0, 1, 0 });
    Q.push({ 0, 2, N-1 });
    while (Q.size()) {
        auto e = Q.top(); Q.pop();
        auto d = e[0], c = e[1], v = e[2];
        if (done[v]) continue;
        done[v] = true;
        colors[v] = c;
        for (auto u : G[v]) {
            if (done[u]) continue;
            Q.push({ d + 1, c, u });
        }
    }

    int wc = 0, bc = 0;
    for (auto c : colors) {
        if (c == 1) // white
            ++wc;
        if (c == 2) // black
            ++bc;
    }
    if (wc > bc) {
        // fennec
        return false;
    } else {
        // snuke
        return true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    G.assign(N, vector<int>());
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    auto ans = solve() ? "Snuke" : "Fennec";
    cout << ans << endl;

    return 0;
}