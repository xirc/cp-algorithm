#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string N;
    cin >> N;
    auto same = (N[0] == N[1] && N[1] == N[2] && N[2] == N[3]);
    cout << (same ? "SAME" : "DIFFERENT") << endl;

    return 0;
}