#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll inf = 1e13;
int A, B, Q;
vector<ll> S, T;

void build() {
    sort(S.begin(), S.end());
    sort(T.begin(), T.end());
}

vector<ll> distLR(vector<ll> const& A, ll x) {
    assert(A.size() >= 1);
    auto it = lower_bound(A.begin(), A.end(), x);
    if (it == A.end()) {
        return { x - A[A.size()-1], inf };
    }
    if (it == A.begin()) {
        return  { inf, A[0] - x };
    }
    auto dr = abs(*it - x);
    --it;
    auto dl = abs(*it - x);

    return { dl, dr };
}

ll query(ll x) {
    auto da = distLR(S, x);
    auto db = distLR(T, x);

    return min({
        max(da[0], db[0]),
        da[0] * 2 + db[1],
        da[0] + db[1] * 2,
        da[1] * 2 + db[0],
        da[1] + db[0] * 2,
        max(da[1], db[1])
    });
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> A >> B >> Q;
    S.assign(A, 0);
    T.assign(B, 0);
    for (int i = 0; i < A; ++i) {
        cin >> S[i];
    }
    for (int i = 0; i < B; ++i) {
        cin >> T[i];
    }

    build();

    for (int i = 0; i < Q; ++i) {
        ll x;
        cin >> x;
        cout << query(x) << endl;
    }

    return 0;
}