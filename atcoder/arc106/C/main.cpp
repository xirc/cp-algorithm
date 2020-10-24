#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solve(int N, int M) {
    if (M < 0) return {};

    vector<vector<int>> ans;
    if (M == 0) {
        int L = 1;
        for (int i = 0; i < N; ++i) {
            ans.push_back({ L++, L++ });
        }
        return ans;
    }

    int L = 1;
    while (M + 1 > 0) {
        --M;
        ans.push_back({ ++L, ++L } );
    }
    ans.push_back({ 1, ++L });
    if (ans.size() > N) return { };
    while (ans.size() < N) {
        ans.push_back({ ++L, ++L });
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    auto ans = solve(N, M);
    if (ans.size() == 0) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i][0] << " " << ans[i][1] << endl;
        }
    }

    return 0;
}