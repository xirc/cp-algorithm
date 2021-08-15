#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;
    vector<int> H;

    cin >> N >> M;
    H.assign(N, 0);
    for (auto &h : H) cin >> h;

    vector<bool> awesome(N, true);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (H[a] <= H[b]) awesome[a] = false;
        if (H[b] <= H[a]) awesome[b] = false;
    }

    int ans = count_if(awesome.begin(), awesome.end(), [](auto b) { return b; });
    cout << ans << endl;

    return 0;
}