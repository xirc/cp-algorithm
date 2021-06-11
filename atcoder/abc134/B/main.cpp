#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, D;
    cin >> N >> D;

    int M = 2 * D + 1;
    int P = (N + M - 1) / M;
    cout << P << endl;

    return 0;
}