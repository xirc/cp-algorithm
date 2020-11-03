#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(int N, vector<int> const& A, vector<int> const& B) {
    map<ll,ll> M;
    for (int i = 0; i < N; ++i) {
        M[A[i]] += B[i];
    }

    vector<pair<ll,ll>> vs;
    for (auto e : M) {
        vs.push_back(e);
    }
    sort(vs.begin(), vs.end());
    reverse(vs.begin(), vs.end());

    const int L = vs.size();
    ll deli = vs[0].first;
    ll pick = 0L;
    for (int i = 0; i < L; ++i) {
        ll new_deli = (i + 1 < L) ? vs[i+1].first : 0L;
        ll new_pick = pick + vs[i].second;
        if (max(new_deli, new_pick) < deli) {
            deli = new_deli;
            pick = new_pick;
        } else break;
    }

    return max(deli, pick);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T, N;
    vector<int> A, B;


    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N;
        A.assign(N, 0);
        B.assign(N, 0);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }
        cout << solve(N, A, B) << endl;
    }

    return 0;
}