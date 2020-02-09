// https://codeforces.com/contest/59/problem/E

#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> adj;
map<tuple<int,int,int>,bool> prohibit;

vector<int> solve() {
    tuple<int,int,int> last;
    map<pair<int,int>,int> prev;
    map<pair<int,int>,bool> used;
    queue<tuple<int,int,int>> Q;

    Q.push({0, 0, 0});
    while (!Q.empty()) {
        auto now = Q.front(); Q.pop();
        int a = get<0>(now), b = get<1>(now), c = get<2>(now);
        if (c == N-1) {
            last = now;
            break;
        }
        for (auto u : adj[c]) {
            if (used[{c,u}]) continue;
            if (prohibit[{b,c,u}]) continue;
            used[{c,u}] = true;
            prev[{b,c}] = a;
            Q.push({b,c,u});
        }
    }

    // No path
    if (get<2>(last) != N-1) {
        return vector<int>();
    }

    vector<int> ans;
    while (true) {
        int a = get<0>(last), b = get<1>(last), c = get<2>(last);
        ans.push_back(c);
        if (c == 0) {
            break;
        }
        last = {prev[{a,b}],a,b};
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int M, K;
    cin >> N >> M >> K;
    adj.assign(N, vector<int>());
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < K; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b, --c;
        prohibit[{a,b,c}] = true;
    }
    auto ans = solve();
    if (ans.size() == 0) {
        cout << -1 << endl;
    } else {
        cout << ans.size() - 1 << endl;
        for (int i = 0; i < ans.size(); ++i) {
            if (i > 0) cout << " ";
            cout << ans[i] + 1;
        }
        cout << endl;
    }

    return 0;
}