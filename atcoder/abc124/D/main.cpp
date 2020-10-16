#include <bits/stdc++.h>

using namespace std;

int solve(int N, int K, string const& S) {
    vector<pair<int,int>> W;
    W.reserve(N);

    if (S[0] == '0') {
        W.push_back({ 0, 0 });
    }

    int i = 0;
    while (i < N) {
        if (S[i] == '0') {
            ++i;
            continue;
        }
        int j;
        for (j = i + 1; j < N; ++j) {
            if (S[j] == '0') break;
        }
        W.push_back({ i, j });
        i = j;
    }

    if (W.back().second < N) {
        W.push_back({ N, N });
    }

    if (W.size() <= K + 1) {
        return S.size();
    }

    int ans = 0;
    for (int i = 0; i + K < W.size(); ++i) {
        ans = max(ans, W[i+K].second - W[i].first);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    string S;
    cin >> N >> K;
    cin >> S;
    cout << solve(N, K, S) << endl;

    return 0;
}