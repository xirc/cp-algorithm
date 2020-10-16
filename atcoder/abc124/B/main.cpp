#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N;
    vector<int> H;

    cin >> N;
    H.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    int ans = 1;
    for (int i = 1; i < N; ++i) {
        bool ok = true;
        for (int j = 0; j < i; ++j) {
            if (H[j] > H[i]) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
    }
    cout << ans << endl;

    return 0;
}