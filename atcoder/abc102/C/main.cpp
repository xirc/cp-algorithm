#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
vector<ll> A;

ll solve() {
    assert(N >= 1);
    for (int i = 0; i < N; ++i) {
        A[i] -= i + 1;
    }
    sort(A.begin(), A.end());
    ll median0 = A[(N-1)/2];
    ll median1 = A[N/2];
    auto score = [&](ll b) {
        ll ans = 0;
        for (auto ai : A) ans += abs(ai - b);
        return ans;
    };
    return min(score(median0), score(median1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout << solve() << endl;

    return 0;
}