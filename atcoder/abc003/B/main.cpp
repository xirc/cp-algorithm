#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S, T;
    cin >> S >> T;
    assert(S.size() == T.size());

    string wildcards = "atcoder";
    bool win = true;
    int N = S.size();
    for (int i = 0; i < N; ++i) {
        if (S[i] == T[i]) continue;
        if (S[i] != '@' && T[i] != '@') {
            win = false;
            break;
        }
        char c = ' ';
        if (S[i] == '@') c = T[i];
        if (T[i] == '@') c = S[i];
        if (c != '@' && wildcards.find(c) == string::npos) {
            win = false;
            break;
        }
    }
    if (win) {
        cout << "You can win" << endl;
    } else {
        cout << "You will lose" << endl;
    }

    return 0;
}