#include <bits/stdc++.h>

inline uint64_t extgcd(
    uint64_t const a,
    uint64_t const b,
    int64_t &x, int64_t &y
)
{
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int64_t x1, y1;
    uint64_t g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int64_t a, b, x, y;
    cin >> a >> b;
    extgcd(a, b, x, y);
    cout << x << " " << y << endl;

    return 0;
}