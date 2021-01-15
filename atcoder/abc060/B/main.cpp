#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool solve(int A, int B, int C) {
    for (int i = 1; i <= B; ++i) {
        if ((A * i) % B == C) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B, C;
    cin >> A >> B >> C;
    auto ans = solve(A, B, C) ? "YES" : "NO";
    cout << ans << endl;

    return 0;
}