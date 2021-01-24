#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

bool solve(int N) {
    if (N % 3 == 0) return true;
    while (N > 0) {
        if (N % 10 == 3) return true;
        N /= 10;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    auto ans = solve(N) ? "YES" : "NO";
    cout << ans << endl;

    return 0;
}