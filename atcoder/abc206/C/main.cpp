#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<int> A;

ll solve() {
    ll num_pairs = ll(N) * N;
    unordered_map<int,int> count;
    for (auto a : A) {
        count[a]++;
    }
    for (auto e : count) {
        int c = e.second;
        num_pairs -= ll(c) * c;
    }
    return num_pairs / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0);
    for (auto &a : A) cin >> a;
    cout << solve() << endl;

    return 0;
}