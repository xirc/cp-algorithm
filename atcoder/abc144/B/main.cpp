#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    bool found = false;
    for (int x = 1; x <= 9; ++x) {
        for (int y = 1; y <= 9; ++y) {
            if (x * y == N) {
                found = true;
                break;
            }
        }
    }
    cout << (found ? "Yes" : "No") << endl;

    return 0;
}