#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int K, S;
    cin >> K >> S;
    
    int ans = 0;
    for (int x = 0; x <= K; ++x) {
        for (int y = 0; y <=K; ++y) {
            int z = S - (x + y);
            if (z <= K && z >= 0) ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}