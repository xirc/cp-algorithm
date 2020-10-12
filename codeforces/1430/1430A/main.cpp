#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int N) {
    for (int C = 0; C < 150; ++C) {
        if (C * 7 > N) break;
        for (int B = 0; B < 250; ++B) {
            if (C * 7 + B * 5 > N) break; 
            int M = N - C * 7 - B * 5;
            if (M % 3 != 0) continue;
            int A = M / 3;
            return { A, B, C };
        }
    }
    return {};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N;
    
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N;
        auto ans = solve(N);
        if (ans.size() == 0) {
            cout << -1 << endl;
        } else {
            cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
        }
    }

    return 0;
}