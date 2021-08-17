#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, M;
string S;

vector<int> solve() {
    vector<int> ans;
    int c = N;
    while (c != 0) {
        bool found = false;
        for (int i = M; i >= 1; --i) {
            if (c - i < 0) continue;
            if (S[c-i] == '0') {
                found = true;
                ans.push_back(i);
                c -= i;
                break;
            }
        }
        // no answer
        if (!found) return {};
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> S;
    auto ans = solve();
    if (ans.size() == 0) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < ans.size(); ++i) {
            if (i > 0) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }

    return 0;
}