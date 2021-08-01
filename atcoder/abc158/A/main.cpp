#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    int a = 0, b = 0;
    for (auto c : S) {
        if (c == 'A') ++a;
        if (c == 'B') ++b;
    }
    bool has_path = a > 0 && b > 0;
    cout << (has_path ? "Yes" : "No") << endl;

    return 0;
}