// https://www.spoj.com/problems/ARBITRAG/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N, M;
map<string,int> id_by_name;
vector<vector<double>> R;

bool solve() {
    const double EPS = 1e-8;
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (R[i][k] * R[k][j] > R[i][j] + EPS) {
                    R[i][j] = R[i][k] * R[k][j];
                }
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        if (R[i][i] > 1 + EPS) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int T = 1; ; T++) {
        cin >> N;
        if (N == 0) break;
        R.assign(N, vector<double>(N, 0));
        for (int i = 0; i < N; ++i) {
            string name;
            cin >> name;
            id_by_name[name] = i;
        }
        cin >> M;
        for (int i = 0; i < M; ++i) {
            string from, to; double r;
            cin >> from >> r >> to;
            int from_id = id_by_name[from];
            int to_id = id_by_name[to];
            R[from_id][to_id] = max(R[from_id][to_id], r);
        }
        auto ans = solve();
        cout << "Case " << T << ": " << (ans ? "Yes" : "No") << endl;
    }

    return 0;
}