#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int X, Y, Z, K;
vector<ll> A, B, C;

vector<ll> solve() {
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    sort(B.begin(), B.end());
    reverse(B.begin(), B.end());
    sort(C.begin(), C.end());
    reverse(C.begin(), C.end());

    struct less {
        bool operator()(vector<int> const& lhs, vector<int> const& rhs) {
            ll ls = A[lhs[0]] + B[lhs[1]] + C[lhs[2]];
            ll rs = A[rhs[0]] + B[rhs[1]] + C[rhs[2]];
            return ls < rs;
        }
    };
    priority_queue<vector<int>, vector<vector<int>>, less> Q;
    set<tuple<int,int,int>> S;
    auto const try_push = [&](int i, int j, int k) {
        if (i >= X || j >= Y || k >= Z) return;
        auto p = make_tuple(i,j,k);
        if (S.count(p) == 0) {
            S.insert(p);
            Q.push({ i, j, k });
        }
    };

    vector<ll> ans;
    ans.reserve(K);
    Q.push({ 0, 0, 0 });
    for (int i = 0; i < K; ++i) {
        auto p = Q.top(); Q.pop();
        auto s = A[p[0]] + B[p[1]] + C[p[2]];
        ans.push_back(s);
        try_push(p[0] + 1, p[1], p[2]);
        try_push(p[0], p[1] + 1, p[2]);
        try_push(p[0], p[1], p[2] + 1);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> X >> Y >> Z >> K;
    A.assign(X, 0);
    B.assign(Y, 0);
    C.assign(Z, 0);
    for (int i = 0; i < X; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < Y; ++i) {
        cin >> B[i];
    }
    for (int i = 0; i < Z; ++i) {
        cin >> C[i];
    }
    auto ans = solve();
    for (int i = 0; i < K; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}