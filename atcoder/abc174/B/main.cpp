#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, D;
    cin >> N >> D;
    ll DD = ll(1) * D * D;
    int points_in_radius = 0;
    for (int i = 0; i < N; ++i) {
        ll X, Y;
        cin >> X >> Y;
        if (X * X + Y * Y <= DD) {
            ++points_in_radius;
        }
    }
    cout << points_in_radius << endl;

    return 0;
}