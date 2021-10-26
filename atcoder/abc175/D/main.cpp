#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, K;
vector<int> P, C;

vector<bool> done;

void dfs(int v, vector<int>& path, int &si) {
    if (done[v]) {
        for (int i = 0; i < (int)path.size(); ++i) {
            if (path[i] == v) {
                si = i;
                break;
            }
        }
        return;
    }
    done[v] = true;
    path.push_back(v);
    dfs(P[v], path, si);
}

ll cycle_score(vector<int> const& path, int si) {
    ll score = 0;
    for (int i = si; i < (int)path.size(); ++i) {
        score += C[path[i]];
    }
    return score;
}

ll solve() {
    done.assign(N, false);
    ll ans = *max_element(C.begin(), C.end());
    for (int v = 0; v < N; ++v) {
        if (done[v]) continue;
        int si;
        vector<int> path;
        dfs(v, path, si);
        int const M = path.size();
        ll const cs = cycle_score(path, si);
        for (int i = 0; i < M; ++i) {
            int steps = K - 1;
            ll score = C[path[i]];
            ans = max(ans, score);
            for (int j = i+1; j < M && steps > 0; ++j) {
                score += C[path[j]];
                ans = max(ans, score);
                --steps;
            }
            if (cs >= 0) {
                int W = max(0, steps / M - 1);
                score += W * cs;
                steps -= W * M;
                ans = max(ans, score);
                for (int j = si; j < M && steps > 0; ++j) {
                    score += C[path[j]];
                    ans = max(ans, score);
                    --steps;
                }
                for (int j = si; j < M && steps > 0; ++j) {
                    score += C[path[j]];
                    ans = max(ans, score);
                    --steps;
                }
            } else {
                for (int j = si; j < i && steps > 0; ++j) {
                    score += C[path[j]];
                    ans = max(ans, score);
                    --steps;
                }
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    P.assign(N, 0);
    C.assign(N, 0);
    for (auto &p : P) {
        cin >> p;
        --p;
    }
    for (auto &c : C) cin >> c;
    cout << solve() << endl;

    return 0;
}