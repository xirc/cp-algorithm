#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    auto ans = S.back() == 'T';
    cout << (ans ? "YES" : "NO") << endl;

    return 0;
}