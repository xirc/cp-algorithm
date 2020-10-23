#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
vector<ll> A, B;

double solve() {
    ll sa = 0, sb = 0;
    for (int i = 0; i < A.size(); ++i) {
        sa += A[i];
    }
    for (int i = 0; i < B.size(); ++i) {
        sb += B[i];
    }
    return sa + (sb / 1e8) * 380000;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0);
    B.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        double x; string u;
        cin >> x >> u;
        if (u == "JPY") {
            A.push_back(x);
        } else if (u == "BTC") {
            B.push_back(x * 1e8);
        } else throw;
    }
    cout << fixed << setprecision(6) <<  solve() << endl;

    return 0;
}