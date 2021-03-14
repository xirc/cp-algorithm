#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> ns(3);
    cin >> ns[0] >> ns[1] >> ns[2];
    sort(ns.begin(), ns.end());
    auto pass = ns == vector<int>({ 5, 5, 7 });
    cout << (pass ? "YES" : "NO") << endl;

    return 0;
}