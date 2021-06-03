#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    ll K;
    vector<int> A;

    cin >> N >> K;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // two pointers
    ll ans = 0;
    ll acc = 0;
    int r = 0;
    for (int l = 0; l < N; ++l) {
        while (r < N && acc < K) {
            acc += A[r];
            ++r;
        }
        if (acc >= K) {
            ans += N - (r-1);
        }
        acc -= A[l];
    }
    cout << ans << endl;

    return 0;
}