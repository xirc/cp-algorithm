#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
vector<int> A;

void solve() {
    assert(N >= 2);
    ll P = abs(A[0]);
    for (int i = 1; i < N; ++i) {
        P += abs(A[i] - A[i-1]);
    }
    P += abs(A[N-1]);

    ll P1 = P - abs(A[0]) - abs(A[1] - A[0]) + abs(A[1]);
    ll Pn = P - abs(A[N-1]) - abs(A[N-1] - A[N-2]) + abs(A[N-2]);
    cout << P1 << endl;
    for (int i = 1; i < N - 1; ++i) {
        ll Pi = P - abs(A[i] - A[i-1]) - abs(A[i] - A[i+1]) + abs(A[i-1] - A[i+1]);
        cout << Pi << endl;
    }
    cout << Pn << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    solve();

    return 0;
}