#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
int X, Y;
vector<int> A, B;

int solve() {
    int const inf = N + 1;
    vector<vector<int>> DPc(X+1, vector<int>(Y+1, inf));
    DPc[0][0] = 0;
    for (int i = 0; i < N; ++i) {
        vector<vector<int>> DPn = DPc;
        for (int a = X; a >= 0; --a) {
            for (int b = Y; b >= 0; --b) {
                int na = min(a + A[i], X);
                int nb = min(b + B[i], Y);
                DPn[na][nb] = min(DPn[na][nb], DPc[a][b] + 1);
            }
        }
        DPc = DPn;
    }
    if (DPc[X][Y] == inf) return -1;
    return DPc[X][Y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> X >> Y;
    A.assign(N, 0); B.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }
    cout << solve() << endl;

    return 0;
}