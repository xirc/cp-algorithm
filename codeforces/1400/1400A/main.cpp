#include <bits/stdc++.h>

using namespace std;

string solve(const string& S, int N) {
    vector<int> M(N);
    for (int i = 0; i < N; ++i) {
        M[i] = S[i] - '0';
    }
    for (int b = 1; b < N; ++b) {
        for (int i = 0; i < N; ++i) {
            int si = S[b + i] - '0';
            if (M[i] == si) continue;
            if (M[i] != si) M[i] = 2;
        }
    }
    vector<char> ans;
    ans.reserve(N);
    for (int i = 0; i < N; ++i) {
        char c;
        if (M[i] == 0) {
            c = '0';
        } else {
            c = '1';
        }
        ans.push_back(c);
    }
    return string(ans.begin(), ans.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N;
    string S;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> N >> S;
        cout << solve(S, N) << endl;
    }

    return 0;
}