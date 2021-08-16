#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> A;

    ll ans = 0;
    map<int,int> count;
    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = N - 1; i >= 0; --i) {
        int s = -A[i]-i;
        ans += count[s];
        count[A[i]-i]++;
    }
    cout << ans << endl;

    return 0;
}