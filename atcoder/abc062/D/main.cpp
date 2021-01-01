#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
vector<int> A;

ll solve() {
    ll sum;
    vector<ll> lsum(N+1, 0);
    vector<ll> rsum(N+1, 0);

    sum = 0;
    priority_queue<int, vector<int>, greater<int>> ql;
    for (int i = 0; i < N; ++i) {
        ql.push(A[i]);
        sum += A[i];
    }
    lsum[0] = sum;
    for (int i = 0; i < N; ++i) {
        auto v = A[N+i];
        ql.push(v);
        sum += v;
        sum -= ql.top();
        ql.pop();
        lsum[i+1] = sum;
    }

    sum = 0;
    priority_queue<int, vector<int>, less<int>> qr;
    for (int i = 2 * N; i < 3 * N; ++i) {
        qr.push(A[i]);
        sum += A[i];
    }
    rsum[0] = sum;
    for (int i = 0; i < N; ++i) {
        auto v = A[2*N-1-i];
        qr.push(A[2*N-1-i]);
        sum += v;
        sum -= qr.top();
        qr.pop();
        rsum[i+1] = sum;
    }

    ll ans = numeric_limits<ll>::lowest();
    for (int i = 0; i <= N; ++i) {
        ans = max(ans, lsum[i] - rsum[N-i]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(3 * N, 0);
    for (int i = 0; i < 3 * N; ++i) {
        cin >> A[i];
    }
    cout << solve() << endl;

    return 0;
}