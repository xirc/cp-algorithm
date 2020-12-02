#include <bits/stdc++.h>

using namespace std;

// o(NK * log(NK) * K)
string solve(string const& S, int K) {
    const int N = S.size();
    vector<string> M;
    for (int l = 0; l < N; ++l) {
        for (int c = 1; c <= K && l + c <= N; ++c) {
            string ss = S.substr(l, c);
            M.push_back(ss);
        }
    }
    sort(M.begin(), M.end());
    M.erase(unique(M.begin(), M.end()), M.end());
    return M[K-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    string S;
    int K;

    cin >> S >> K;
    cout << solve(S, K) << endl;

    return 0;
}