#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    vector<vector<bool>> G(N, vector<bool>(N, false));

    for (int i = 0; i < N; ++i) {
        int u, v, K;
        cin >> u >> K;
        for (int j = 0; j < K; ++j) {
            cin >> v;
            G[u-1][v-1] = true;
        }
    }

    for (int u = 0; u < N; ++u) {
        for (int v = 0; v < N; ++v) {
            if (v > 0) cout << " ";
            cout << G[u][v];
        }
        cout << endl;
    }

    return 0;
}