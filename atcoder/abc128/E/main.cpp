#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<ll> S, T, X;

vector<ll> xs;
vector<int> indice;

void build() {
    // projection
    for (int i = 0; i < N; ++i) {
        S[i] = S[i] - X[i];
        T[i] = T[i] - X[i];
    }

    // sort asc based on X
    auto ss = vector<array<ll,3>>(N);
    for (int i = 0; i < N; ++i) {
        ss[i] = { X[i], S[i], T[i] };
    }
    sort(ss.begin(), ss.end());
    for (int i = 0; i < N; ++i) {
        X[i] = ss[i][0];
        S[i] = ss[i][1];
        T[i] = ss[i][2];
    }

    // compress axis
    set<ll> ps;
    for (int i = 0; i < N; ++i) {
        ps.insert(S[i]);
        ps.insert(T[i]);
    }
    for (auto x : ps) {
        xs.push_back(x);
    }

    // make indice
    int const M = 2 * N;
    indice.assign(M, N + 1);
    priority_queue<tuple<int,int,int>> events;
    set<int> is;
    for (int i = 0; i < N; ++i) {
        int si = distance(xs.begin(), lower_bound(xs.begin(), xs.end(), S[i]));
        int ti = distance(xs.begin(), lower_bound(xs.begin(), xs.end(), T[i]));
        events.push({ -si, 1, i });
        events.push({ -ti, -1, i });
    }
    for (int i = 0; i < M; ++i) {
        while (events.size() && -get<0>(events.top()) <= i) {
            auto e = events.top();
            events.pop();
            if (get<1>(e) > 0) {
                is.insert(get<2>(e));
            } else {
                is.erase(get<2>(e));
            }
        }
        if (is.size()) {
            indice[i] = *is.begin();
        }
    }

}

ll query(ll D) {
    auto it = upper_bound(xs.begin(), xs.end(), D);
    if (it == xs.begin()) return -1;
    --it;
    int i = distance(xs.begin(), it);
    if (indice[i] == N + 1) return -1;
    return X[indice[i]];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int Q;
    cin >> N >> Q;
    S.assign(N, 0);
    T.assign(N, 0);
    X.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> S[i] >> T[i] >> X[i];
    }
    build();
    for (int i = 0; i < Q; ++i) {
        int D;
        cin >> D;
        cout << query(D) << endl;
    }

    return 0;
}