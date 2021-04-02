#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll factorial(int n) {
    ll f = 1;
    while (n > 0) {
        f *= n;
        --n;
    }
    return f;
}

int N;
vector<int> C;

ff solve() {
    ll score = 0;
    vector<array<int,2>> cs(N, { 0, 0 });
    for (int i = 0; i < N; ++i) {
        cs[i] = { C[i], i };
    }
    sort(cs.begin(), cs.end());
    do {
        for (int i = 0; i < N; ++i) {
            int numDiv = 0;
            for (int j = 0; j < i; ++j) {
                if (cs[i][0] % cs[j][0] == 0) numDiv++;
            }
            if (numDiv % 2 == 0) {
                score++;
            }
        }
    } while (next_permutation(cs.begin(), cs.end()));
    return score / ff(factorial(N));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    C.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
    }
    cout << fixed << setprecision(12) << solve() << endl;

    return 0;
}