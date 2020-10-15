#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> C, V;

    cin >> N;
    V.assign(N, 0);
    C.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> V[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += max(0, V[i] - C[i]);
    }
    cout << ans << endl;

    return 0;
}