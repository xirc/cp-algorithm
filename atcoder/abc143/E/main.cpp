#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

const ll inf = 1e16;
int N, L;
vector<vector<ll>> G;

void reduce() {
    // Floyd Warshall
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
}

void build() {
    for (int i = 0; i < N; ++i) {
        G[i][i] = 0;
    }
    reduce();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) G[i][j] = 0;
            else if (G[i][j] <= L) G[i][j] = 1;
            else G[i][j] = inf;
        }
    }
    reduce();
}

int query(int u, int v) {
    if (G[u][v] == inf)
        return -1;
    return G[u][v] - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int M;
    cin >> N >> M >> L;
    G.assign(N, vector<ll>(N, inf));
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        G[a][b] = c;
        G[b][a] = c;
    }
    build();

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int s, t;
        cin >> s >> t;
        --s, --t;
        cout << query(s, t) << endl;
    }

    return 0;
}