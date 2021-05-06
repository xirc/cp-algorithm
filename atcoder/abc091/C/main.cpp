#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<pair<int,int>> rs, bs;

int solve() {
    // x asc, y asc
    sort(bs.begin(), bs.end());
    // y desc x desc
    sort(rs.begin(), rs.end(), [](auto const& lhs, auto const& rhs) {
        if (lhs.second != rhs.second) return lhs.second > rhs.second;
        return lhs.first > rhs.first;
    });

    int count = 0;
    vector<bool> used(N, false);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (used[j]) continue;
            if (bs[i].first <= rs[j].first) continue;
            if (bs[i].second <= rs[j].second) continue;
            used[j] = true;
            ++count;
            break;
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    rs.assign(N, { 0, 0 });
    bs.assign(N, { 0, 0 });
    for (int i = 0; i < N; ++i) {
        cin >> rs[i].first >> rs[i].second;
    }
    for (int i = 0; i < N; ++i) {
        cin >> bs[i].first >> bs[i].second;
    }
    cout << solve() << endl;

    return 0;
}