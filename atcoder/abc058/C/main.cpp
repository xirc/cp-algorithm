#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int N;
vector<string> S;

string solve() {
    vector<int> count(26,50);
    for (auto s : S) {
        vector<int> t(26,0);
        for (auto c : s) {
            ++t[c-'a'];
        }
        for (int i = 0; i < 26; ++i) {
            count[i] = min(count[i], t[i]);
        }
    }
    vector<char> ans;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < count[i]; ++j) {
            ans.push_back('a' + i);
        }
    }
    return string(ans.begin(), ans.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    S.assign(N, "");
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }
    cout << solve() << endl;

    return 0;
}