#include <bits/stdc++.h>

using namespace std;

int solve(int N, string const& S) {
    map<int, int> count;
    vector<int> next(N, -1);

    for (int i = 0; i < N; ++i) {
        int j;
        for (j = i + 1; j < N; ++j) {
            if (S[i] != S[j]) break;
        }
        if (j > i + 1) {
            count[i] = j - i;
        }
        next[i] = j;
        i = j - 1;
    }

    int ans = 0;
    for (int i = 0; i < N;) {
        ++ans;
        if (count.empty()) {
            i = next[i];
            if (i < N) i = next[i];
        } else {
            auto it = count.begin();
            --it->second;
            if (it->second == 1 || it->first < next[i]) count.erase(it);
            i = next[i];
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N;
    string S;
    
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N >> S;
        cout << solve(N, S) << endl;
    }

    return 0;
}