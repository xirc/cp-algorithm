#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B, C;
    cin >> A >> B >> C;
    vector<int> D(101, 0);
    D[A] = D[B] = D[C] = 1;
    for (int i = 100; i > 0; --i) {
        D[i-1] += D[i];
    }
    cout << D[A] << endl;
    cout << D[B] << endl;
    cout << D[C] << endl;

    return 0;
}