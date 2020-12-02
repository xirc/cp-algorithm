#include <bits/stdc++.h>

using namespace std;

int solve(int X) {
    int ans = 1;
    for (int b = 1; b * b <= X; ++b) {
        for (int e = 2; e <= 10; ++e) {
            if (pow(b, e) > X) break;
            ans = max(ans, (int)pow(b, e));
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int X;
    cin >> X;
    cout << solve(X) << endl;

    return 0;
}