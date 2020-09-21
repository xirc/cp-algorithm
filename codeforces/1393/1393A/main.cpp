#include <bits/stdc++.h>

using namespace std;

// N = 1, A = 1
// N = 2, A = 2
// N = 3, A = 2
// N = 4, A = 3
// N = 5, A = 3
// N = 6, A = 4
// N = 7, A = 4
// N = 8, A = 5
// N = 9, A = 5

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T, N;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N;
        auto ans = (N / 2) + 1;
        cout << ans << endl;
    }

    return 0;
}