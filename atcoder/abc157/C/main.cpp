#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, M;
vector<int> S, C;

int solve() {
    map<int,int> ds;
    for (int i = 0; i < M; ++i) {
        if (ds.count(S[i]) > 0 && ds[S[i]] != C[i]) return -1;
        ds[S[i]] = C[i];
    }
    if (N == 1) {
        return (ds.count(0) > 0 ? ds[0] : 0);
    }
    if (ds.count(0) > 0 && ds[0] == 0) return -1;
    int ans = (ds.count(0) > 0 ? ds[0] : 1);
    for (int i = 1; i < N; ++i) {
        ans *= 10;
        ans += ds[i];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    S.assign(M, 0);
    C.assign(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> S[i] >> C[i];
        --S[i];
    }
    cout << solve() << endl;

    return 0;
}