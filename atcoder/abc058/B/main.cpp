#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string O, E;
    cin >> O >> E;
    const int N = O.size() + E.size();
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            cout << O[i/2];
        } else {
            cout << E[i/2];
        }
    }
    cout << endl;

    return 0;
}