#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N; ll X;
    string S;
    
    cin >> N >> X >> S;
    for (auto c : S) {
        if (c == 'o') {
            ++X;
        } else if (c == 'x') {
            --X;
            X = max(ll(0), X);
        }
    }
    cout << X << endl;

    return 0;
}