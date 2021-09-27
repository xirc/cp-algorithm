#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    int const inf = 2e9;
    int min_price = inf;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int A, P, X;
        cin >> A >> P >> X;
        X = max(0, X - A);
        if (X > 0) {
            min_price = min(min_price, P);
        }
    }
    
    cout << (min_price == inf ? -1 : min_price) << endl;

    return 0;
}