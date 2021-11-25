#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string F;
    cin >> F;
    auto X = F.substr(0, F.size() - 2);
    auto Y = F.substr(F.size()-1, 1);

    if (Y <= "2") {
        cout << X << "-" << endl;
    } else if (Y <= "6") {
        cout << X << endl;
    } else {
        cout << X << "+" << endl;
    }

    return 0;
}