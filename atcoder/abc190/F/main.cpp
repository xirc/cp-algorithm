#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<int> A;

void merge(vector<int> const& ls, vector<int> const& rs, vector<int>& xs, ll &ic) {
    int k = 0;
    int i = 0, j = 0;
    while (i < ls.size() && j < rs.size()) {
        if (ls[i] <= rs[j]) {
            xs[k++] = ls[i++];
        } else {
            ic += (ls.size() - i);
            xs[k++] = rs[j++];
        }
    }
    while (i < ls.size()) {
        xs[k++] = ls[i++];
    }
    while (j < rs.size()) {
        xs[k++] = rs[j++];
    }
}

void msort(vector<int>& xs, ll &ic) {
    int const n = xs.size();
    if (n == 1) {
        return;
    }
    vector<int> ls, rs;
    for (int i = 0; i < n/2; ++i) {
        ls.push_back(xs[i]);
    }
    for (int i = n/2; i < n; ++i) {
        rs.push_back(xs[i]);
    }
    msort(ls, ic);
    msort(rs, ic);
    merge(ls, rs, xs, ic);
}

vector<ll> solve() {
    deque<int> Q(A.begin(), A.end());
    ll ic = 0;
    msort(A, ic);
    vector<ll> ans;
    ans.push_back(ic);
    for (int i = 0; i < N - 1; ++i) {
        auto v = Q.front(); Q.pop_front();
        ic += N - 1 - 2 * v;
        Q.push_back(v);
        ans.push_back(ic);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0);
    for (auto &a : A) cin >> a;
    auto ans = solve();
    for (auto v : ans) {
        cout << v << endl;
    }

    return 0;
}