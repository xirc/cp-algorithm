#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, M;
vector<bitset<10>> ss;
vector<int> ps;

bool is_all_turned_on(bitset<10> const& bs) {
    for (int i = 0; i < M; ++i) {
        int c = (ss[i] & bs).count() % 2;
        if (c != ps[i]) return false;
    }
    return true;
}

int solve() {
    int const U = 1 << N;
    int num_states = 0;
    for (int s = 0; s < U; ++s) {
        bitset<10> bs(s);
        if (is_all_turned_on(bs)) ++num_states;
    }
    return num_states;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    ss.assign(M, bitset<10>(0));
    ps.assign(M, 0);
    for (int i = 0; i < M; ++i) {
        int k, s;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            cin >> s;
            --s;
            ss[i][s] = true;
        }
    }
    for (int i = 0; i < M; ++i) {
        cin >> ps[i];
    }
    cout << solve() << endl;

    return 0;
}