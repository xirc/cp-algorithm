#include <bits/stdc++.h>

using namespace std;

bool can_put_white(const string& S, int x) {
    if (S[x] != '.') return false;
    int i;
    for (i = x + 1; i < S.size(); ++i) {
        if (S[i] == '.') return true;
        if (S[i] == 'B') break;
    }
    if (i == S.size()) return true;
    for (i = x - 1; i >= 0; --i) {
        if (S[i] == '.') return true;
        if (S[i] == 'B') return false;
    }
    return true;
}

int count_capture_black(const string& S, int x) {
    int maxi = 0;
    int i;
    for (i = x + 1; i < S.size(); ++i) {
        if (S[i] != 'B') break;
    }
    if (i < S.size() && S[i] == 'W') {
        maxi = max(maxi, i - x - 1);
    }
    for (i = x - 1; i >= 0; --i) {
        if (S[i] != 'B') break;
    }
    if (i < S.size() && S[i] == 'W') {
        maxi = max(maxi, x - i - 1);
    }
    return maxi;
}

// O(N^2)
int solve(const string& S) {
    int ans = 0;
    for (int i = 0; i < S.size(); ++i) {
        if (can_put_white(S, i)) {
            ans = max(ans, count_capture_black(S, i));
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int L;
    string S;
    cin >> L >> S;
    cout << solve(S) << endl;

    return 0;
}