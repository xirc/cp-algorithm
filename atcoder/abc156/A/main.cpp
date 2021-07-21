#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, R;
    cin >> N >> R;
    int IR = R + 100 * max(0, 10 - N);
    cout << IR << endl;

    return 0;
}