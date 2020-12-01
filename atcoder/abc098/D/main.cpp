#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
vector<int> A;

ll solve() {
    ll ans = 0;
    ll count = 0;
    ll x = 0;
    int l = 0, r = 0;
    while (l < N) {
        if (r < l) {
            ++r;
            continue;
        }
        if (r == N || x & A[r]) {
            ans += count;
            x ^= A[l];
            ++l;
            if (l <= r) {
                --count;
            }
            continue;
        }
        ++count;
        x ^= A[r];
        ++r;
    }
    ans += count;
    return ans;
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