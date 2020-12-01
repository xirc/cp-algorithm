#include <bits/stdc++.h>

using namespace std;

int N;
string S;

int count_same(int K) {
    int count = 0;
    set<char> ls;
    set<char> rs;
    for (int i = 0; i < K; ++i) {
        ls.insert(S[i]);
    }
    for (int i = K; i < N; ++i) {
        rs.insert(S[i]);
    }
    for (auto v : ls) {
        if (rs.count(v)) {
            ++count;
        }
    }
    return count;
}

int solve() {
    int ans = 0;
    for (int k = 1; k < N; ++k) {
        ans = max(ans, count_same(k));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> S;
    cout << solve() << endl;

    return 0;
}