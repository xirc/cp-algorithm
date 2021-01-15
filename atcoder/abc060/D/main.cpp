#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, W;
vector<int> wss, vss;

int solve() {
    vector<deque<int>> v(4);

    v[0].push_back(vss[0]);
    for (int i = 1; i < N; ++i) {
        int dw = wss[i] - wss[0];
        assert(dw >= 0 && dw <= 3);
        v[dw].push_back(vss[i]);
    }

    for (int i = 0; i < 4; ++i) {
        sort(v[i].begin(), v[i].end());
        reverse(v[i].begin(), v[i].end());
        v[i].push_front(0);
        for (int j = 1; j < v[i].size(); ++j) {
            v[i][j] += v[i][j-1];
        }
    }

    int ans = 0;
    for (int i = 0; i < v[0].size(); ++i) {
        for (int j = 0; j < v[1].size(); ++j) {
            for (int k = 0; k < v[2].size(); ++k) {
                for (int l = 0; l < v[3].size(); ++l) {
                    ll ww = ll(wss[0])*i + ll(wss[0]+1)*j + ll(wss[0]+2)*k + ll(wss[0]+3)*l;
                    int vv = v[0][i] + v[1][j] + v[2][k] + v[3][l];
                    if (ww > W) continue;
                    ans = max(ans, vv);
                }
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> W;
    wss.assign(N, 0);
    vss.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> wss[i] >> vss[i];
    }
    cout << solve() << endl;

    return 0;
}