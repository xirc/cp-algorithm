#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int count(string const& S) {
    int const n = S.size();
    int ans = 0;
    int i = 0;
    int l = 0;
    int m = 0;
    while (i < n) {
        if (S[i] == '1') {
            if (m == 0) l = i;
            ++m;
        } else if (m > 0) {
            int r = n - l - m;
            int k = min({ n - l, n - r, l + m, m + r });
            ans = max(ans, k);
            m = 0;
        }
        ++i;
    }
    if (m > 0) {
        int r = n - l - m;
        int k = min({ n - l, n - r, l + m, m + r });
        ans = max(ans, k);
    }
    return ans;
}

int solve(string& S) {
    int ans = count(S);
    for (int i = 0; i < S.size(); ++i) {
        S[i] = S[i] == '0' ? '1' : '0';
    }
    ans = max(ans, count(S));
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    cout << solve(S) << endl;

    return 0;
}