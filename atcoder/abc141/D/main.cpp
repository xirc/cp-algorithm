#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;

    priority_queue<array<int,3>> Q;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        Q.push({ A, A, 0 });
    }

    for (int i = 0; i < M; ++i) {
        auto a = Q.top(); Q.pop();
        int x = a[1], y = a[2];
        Q.push({ x >> min(31, (y+1)), x, y + 1 });
    }
    
    ll ans = 0;
    while (Q.size()) {
        auto e = Q.top(); Q.pop();
        ans += e[0];
    }
    cout << ans << endl;

    return 0;
}