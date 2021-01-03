#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int N;
vector<int> A, B;

vector<vector<int>> G;
vector<int> depth;
vector<ll> cs;

void build() {
    // Graph
    G.assign(N, vector<int>());
    for (int i = 0; i < N - 1; ++i) {
        int a = A[i], b = B[i];
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // BFS
    depth.assign(N, N);
    queue<int> Q;
    Q.push(0);
    depth[0] = 0;
    while (Q.size()) {
        int v = Q.front();
        Q.pop();
        for (auto u : G[v]) {
            if (depth[u] < N) continue;
            depth[u] = depth[v] + 1;
            Q.push(u);
        }
    }

    // score
    cs.assign(N, 0);
}

void update(int a, int b, int x) {
    if (depth[a] > depth[b]) {
        cs[a] += x;
    } else {
        cs[0] += x;
        cs[b] -= x;
    }
}

void finalize() {
    // BFS
    queue<int> Q;
    Q.push(0);
    while(Q.size()) {
        int v = Q.front();
        Q.pop();
        for (auto u : G[v]) {
            if (depth[u] <= depth[v]) continue;
            cs[u] += cs[v];
            Q.push(u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N - 1, 0);
    B.assign(N - 1, 0);
    for (int i = 0; i < N - 1; ++i) {
        cin >> A[i] >> B[i];
        --A[i], --B[i]; // 0-indexed
    }
    build();

    int Q;
    int t, e, x;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        cin >> t >> e >> x;
        --e;
        if (t == 1) {
            int a = A[e], b = B[e];
            update(a, b, x);
        } else if (t == 2) {
            int a = A[e], b = B[e];
            update(b, a, x);
        } else throw;
    }

    finalize();
    for (int i = 0; i < N; ++i) {
        cout << cs[i] << endl;
    }

    return 0;
}