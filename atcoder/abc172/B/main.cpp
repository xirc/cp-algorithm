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

    int ops = 0;
    int N = S.size();
    for (int i = 0; i < N; ++i) {
        if (S[i] != T[i]) ++ops;
    }
    cout << ops << endl;

    return 0;
}