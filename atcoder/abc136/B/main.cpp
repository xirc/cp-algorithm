#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int dig(int n) {
    int c = 0;
    while (n > 0) {
        ++c;
        n /= 10;
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        if (dig(i) % 2 == 1) ++ ans;
    }
    cout << ans << endl;

    return 0;
}