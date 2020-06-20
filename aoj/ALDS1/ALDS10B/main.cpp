#include <bits/stdc++.h>

using namespace std;

// O(N^3)
int solve(vector<pair<int,int>>& M) {
    const int inf = numeric_limits<int>::max();
    const int N = M.size();
    vector<vector<pair<int,int>>> rc(N, vector<pair<int,int>>(N));
    vector<vector<int>> count(N, vector<int>(N, inf));
    for (int i = 0; i < N; ++i) {
        rc[i][0] = M[i];
        count[i][0] = 0;
    }
    for (int w = 1; w < N; ++w) {
        for (int i = 0; i < N; ++i) {
            if (i + w >= N) continue;
            for (int l = 1; l <= w; ++l) {
                auto a = rc[i][l-1];
                auto ac = count[i][l-1];
                auto b = rc[i+l][w-l];
                auto bc = count[i+l][w-l];
                int cnt = ac + bc + a.first * a.second * b.second;
                if (cnt < count[i][w]) {
                    rc[i][w] = { a.first, b.second };
                    count[i][w] = cnt;
                }
            }
        }
    }
    return count[0][N-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<pair<int,int>> M(N);
    for (int i = 0; i < N; ++i) {
        cin >> M[i].first >> M[i].second;
    }
    auto ans = solve(M);
    cout << ans << endl;

    return 0;
}