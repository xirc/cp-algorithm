#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    int Q;
    cin >> S >> Q;

    deque<char> buf(S.begin(), S.end());
    bool rev = false;

    for (int qq = 0; qq < Q; ++qq) {
        int T, F; char C;
        cin >> T;
        if (T == 1) {
            rev = !rev;
        } else if (T == 2) {
            cin >> F >> C;
            bool fr = (F == 1) ^ rev;
            if (fr) buf.push_front(C);
            else buf.push_back(C);
        } else throw;
    }

    auto T = string(buf.begin(), buf.end());
    if (rev) reverse(T.begin(), T.end());
    cout << T << endl;

    return 0;
}