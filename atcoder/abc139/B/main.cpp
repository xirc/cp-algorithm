#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B;
    cin >> A >> B;

    int c = 0;
    int p = 1;
    while (p < B) {
        p += A - 1;
        ++c;
    }
    cout << c << endl;

    return 0;
}