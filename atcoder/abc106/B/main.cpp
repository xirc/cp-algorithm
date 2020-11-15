#include <bits/stdc++.h>

using namespace std;

int nrf(int N) {
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        if (N % i == 0) ++ans;
    }
    return ans;
}

int solve(int N) {
    int ans = 0;
    for (int i = 1; i <= N; i += 2) {
        if (nrf(i) == 8) {
            ++ans;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    cout << solve(N) << endl;

    return 0;
}