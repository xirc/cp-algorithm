#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;

    priority_queue<int> Q;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        Q.push(A);
    }

    for (int i = 0; i < M; ++i) {
        auto a = Q.top(); Q.pop();
        Q.push(a >> 1);
    }
    
    ll ans = 0;
    while (Q.size()) {
        auto a = Q.top(); Q.pop();
        ans += a;
    }
    cout << ans << endl;

    return 0;
}