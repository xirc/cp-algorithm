// http://codeforces.com/problemset/problem/295/B

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int inf = 1e8;
int N;
vector<vector<int>> D;
vector<int> erase_verts;

vector<long long> solve() {
    vector<long long> ans;
    set<int> verts;
    for (auto it = erase_verts.rbegin(); it != erase_verts.rend(); ++it) {
        auto k = *it;
        verts.insert(k);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
        long long distance = 0;
        for (auto v : verts) {
            for (auto u : verts) {
                if (v == u) continue;
                distance += D[v][u];
            }
        }
        ans.push_back(distance);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    D.assign(N, vector<int>(N, inf));
    erase_verts.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> D[i][j];
        }
    }
    for (int i = 0; i < N; ++i) {
        cin >> erase_verts[i];
        erase_verts[i]--;
    }

    auto ans = solve();
    for (int i = 0; i < ans.size(); ++i) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}