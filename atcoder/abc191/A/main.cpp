#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int V, T, S, D;
    cin >> V >> T >> S >> D;

    if (V * T <= D && D <= V * S) {
        cout << "No" << endl;
    } else{
        cout << "Yes" << endl;
    }


    return 0;
}