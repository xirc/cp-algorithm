#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, K;
vector<int> A;

int solve() {
    int c = 0;
    for (int i = 0; i < N; i+= K) {
        ++c;
        if (i > 0) i -= 1;
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    A.assign(N, 0);
    for (auto &a : A) cin >> a;

    cout << solve() << endl;

    return 0;
}