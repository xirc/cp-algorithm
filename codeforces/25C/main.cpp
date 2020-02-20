// http://codeforces.com/contest/25/problem/C

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int inf = 1e8;
struct edge { int from, to, distance; };
int N, M;
vector<vector<int>> D;
vector<edge> E;

vector<long long> solve() {
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
    vector<long long> ans;
    for (auto e : E) {
        int from = e.from, to = e.to, distance = e.distance;
        D[from][to] = min(D[from][to], distance);
        D[to][from] = min(D[to][from], distance);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                D[i][j] = min(D[i][j], D[i][from] + D[from][to] + D[to][j]);
                D[i][j] = min(D[i][j], D[i][to] + D[to][from] + D[from][j]);
            }
        }
        long long sum = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                sum += D[i][j];
            }
        }
        sum /= 2;
        ans.push_back(sum);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    D.assign(N, vector<int>(N, inf));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> D[i][j];
        }
    }
    cin >> M;
    E.assign(M, {});
    for (int i = 0; i < M; ++i) {
        cin >> E[i].from >> E[i].to >> E[i].distance;
        E[i].from--, E[i].to--;
    }

    auto ans = solve();
    for (int i = 0; i < ans.size(); ++i) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}