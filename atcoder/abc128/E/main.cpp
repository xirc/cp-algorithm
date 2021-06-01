#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, Q;
vector<int> S, T, X;
vector<int> D;

vector<int> solve() {

    multiset<int> xs;
    priority_queue<array<int,3>> events;

    // make events
    for (int i = 0; i < N; ++i) {
        events.push({ -(S[i] - X[i]),  1, X[i] });
        events.push({ -(T[i] - X[i]), -1, X[i] });
    }

    // sort queries
    vector<array<int,2>> qs;
    for (int i = 0; i < Q; ++i) {
        qs.push_back({ D[i], i });
    }
    sort(qs.begin(), qs.end());

    // process queries
    vector<int> ans(Q, -1);
    for (auto q : qs) {
        while (events.size() && -events.top()[0] <= q[0]) {
            auto e = events.top();
            events.pop();
            if (e[1] > 0) {
                xs.insert(e[2]);
            } else {
                xs.erase(xs.find(e[2]));
            }
        }
        if (xs.size()) {
            ans[q[1]] = *xs.begin();
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> Q;
    S.assign(N, 0);
    T.assign(N, 0);
    X.assign(N, 0);
    D.assign(Q, 0);

    for (int i = 0; i < N; ++i) {
        cin >> S[i] >> T[i] >> X[i];
    }
    for (int i = 0; i < Q; ++i) {
        cin >> D[i];
    }

    auto ans = solve();
    for (auto x : ans) {
        cout << x << endl;
    }

    return 0;
}