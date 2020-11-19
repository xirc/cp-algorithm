#include <bits/stdc++.h>

using namespace std;

bool solve(int N) {
    for (int x = 0; x < 30; ++x) {
        if (x * 4 > N) continue;
        for (int y = 0; y < 20; ++y) {
            if (x * 4 + y * 7 > N) continue;
            if (x * 4 + y * 7 == N) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    auto ans = solve(N) ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}