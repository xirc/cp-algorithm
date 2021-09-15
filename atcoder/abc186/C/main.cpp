#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

bool contains7_on_10base(int N) {
    while (N > 0) {
        if (N % 10 == 7) return true;
        N /= 10;
    }
    return false;
}

bool contains7_on_8base(int N) {
    while (N > 0) {
        if (N % 8 == 7) return true;
        N /= 8;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        if (contains7_on_10base(i)) continue;
        if (contains7_on_8base(i)) continue;
        ++ans;
    }
    cout << ans << endl;

    return 0;
}