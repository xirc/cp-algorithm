#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B;
    string op;

    cin >> A >> op >> B;

    int ans = 0;
    if (op == "+") {
        ans = A + B;
    } else if (op == "-") {
        ans = A - B;
    } else throw;
    cout << ans << endl;

    return 0;
}