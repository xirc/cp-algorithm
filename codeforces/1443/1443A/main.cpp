#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int N) {
    const int M = N * 4;
    vector<int> vs;
    for (int i = M; i > 0 && vs.size() < N; i -= 2) {
        bool ng = any_of(vs.begin(), vs.end(), [&](int v) {
            return v % i == 0;
        });
        if (!ng) {
            vs.push_back(i);
        }
    }
    return vs;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T, N;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N;
        auto ans = solve(N);
        for (int i = 0; i < N; ++i) {
            if (i > 0) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }

    return 0;
}