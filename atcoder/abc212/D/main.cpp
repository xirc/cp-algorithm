#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll base = 0;
    priority_queue<ll, vector<ll>, greater<ll>> min_heap;

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int P, X;
        cin >> P;
        if (P == 1) {
            cin >> X;
            min_heap.push(X - base);
        } else if (P == 2) {
            cin >> X;
            base += X;
        } else if (P == 3) {
            auto v = min_heap.top(); min_heap.pop();
            cout << (v + base) << endl;
        } else throw;
    }

    return 0;
}