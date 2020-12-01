#include <bits/stdc++.h>

using namespace std;

int N;
string S;

int solve() {
    vector<int> ws(N, 0), es(N, 0);
    for (int i = 0; i < N; ++i) {
        if (i > 0) ws[i] = ws[i-1];
        if (S[i] == 'W') ++ws[i];
    }
    for (int i = N - 1; i >= 0; --i) {
        if (i < N - 1) es[i] = es[i+1];
        if (S[i] == 'E') ++es[i];
    }

    int ans = N;
    for (int i = 0; i < N; ++i) {
        int w = i - 1 >= 0 ? ws[i-1] : 0;
        int e = i + 1 < N ? es[i+1] : 0;
        ans = min(ans, w + e);
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