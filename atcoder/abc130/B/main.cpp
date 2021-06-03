#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, X;
    vector<int> L;
    
    cin >> N >> X;
    L.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> L[i];
    }
    for (int i = 1; i < N; ++i) {
        L[i] += L[i-1];
    }
    int m = distance(L.begin(), lower_bound(L.begin(), L.end(), X + 1));
    cout << m + 1 << endl;

    return 0;
}