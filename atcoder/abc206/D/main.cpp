#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

vector<int> dsu;
void init(int N) {
    dsu.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        dsu[i] = i;
    }
}
int find(int v) {
    if (v != dsu[v]) {
        dsu[v] = find(dsu[v]);
    }
    return dsu[v];
}
bool unite(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) {
        return false;
    }
    dsu[v] = u;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> A;
    
    cin >> N;
    A.assign(N, 0);
    for (auto &a : A) cin >> a;

    int ops = 0;
    init(200001);
    for (int i = 0; i * 2 < N; ++i) {
        auto x = A[i], y = A[N-1-i];
        if (unite(x,y)) ++ops;
    }
    cout << ops << endl;

    return 0;
}