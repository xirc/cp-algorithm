#include <bits/stdc++.h>

using namespace std;

int N, W;
vector<int> vss, wss;

// O(NW)
int solve() {
    int ans = 0;
    vector<int> values(W + 1, 0);
    auto update = [&](int w, int v) {
        values[w] = max(values[w], v);
        ans = max(ans, values[w]);
    };
    for (int i = 0; i < N; ++i) {
        if (wss[i] > W) continue;
        for (int w = W; w >= 0; --w) {
            if (w != 0 && values[w] == 0) continue;
            int nw = w + wss[i];
            if (nw > W) continue;
            int nv = values[w] + vss[i];
            update(nw, nv);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> W;
    vss.assign(N, 0);
    wss.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> vss[i] >> wss[i];
    }
    cout << solve() << endl;

    return 0;
}