#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int N, A, B;
vector<ll> vs;

vector<vector<ll>> comb;
void build(int M) {
    comb.assign(M, vector<ll>(M, 0));
    comb[0][0] = 1;
    for (int i = 1; i < M; ++i) {
        comb[i][0] = 1;
        for (int j = 1; j < M; j++) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }
}

pair<double,ll> solve() {
    build(N+1);

    map<ll,int,greater<ll>> mp;
    for (int i = 0; i < N; ++i) {
        mp[vs[i]]++;
    }

    ll sum = 0;
    int acc = 0;
    for (auto e : mp) {
        auto v = e.first;
        auto c = e.second;
        if (acc + c < A) {
            acc += c;
            sum += ll(v) * c;
            continue;
        } else if (acc == 0) {
            assert(sum == 0);
            ll ans = 0;
            for (int k = A; k <= min(c,B); ++k) {
                ans += comb[c][k];
            }
            return make_pair(v, ans);
        } else {
            int r = A - acc;
            sum += ll(v) * r;
            return make_pair(double(sum) / A, comb[c][r]);
        }
    }
    throw;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> A >> B;
    vs.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> vs[i];
    }

    double avg;
    ll com;
    tie(avg,com) = solve();
    cout << fixed << setprecision(6) << avg << endl;
    cout << com << endl;

    return 0;
}