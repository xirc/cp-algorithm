#include <bits/stdc++.h>

using namespace std;

int solve(const string& str) {
    priority_queue<int> Q;

    int nseq = 0;
    for (auto ch : str) {
        if (ch == '1') {
            ++nseq;
        } else if (nseq > 0) {
            Q.push(nseq);
            nseq = 0;
        }
    }
    if (nseq > 0) {
        Q.push(nseq);
    }

    int ans = 0;
    while (Q.size()) {
        ans += Q.top(); Q.pop();
        if (Q.size()) Q.pop();
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    string s;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> s;
        cout << solve(s) << endl;
    }

    return 0;
}