#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

vector<int> solve(string const& S) {
    int const N = S.size();
    vector<int> ans(N, 0);
    int l = 0;
    while (l < N) {
        assert(S[l] == 'R');
        int i = l;
        for (; i < N; ++i) {
            if (S[i] != 'R') break;
        }
        int a = i - l - 1;
        ans[i-1] += 1 + a / 2;
        ans[i] += 1 + (a + 1) / 2;

        int r = i;
        for (; i < N; ++i) {
            if (S[i] != 'L') break;
        }
        int b = i - r - 1;
        ans[r-1] += (b + 1) / 2;
        ans[r] += b / 2;
        l = i;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    auto ans = solve(S);
    for (int i = 0; i < ans.size(); ++i) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}