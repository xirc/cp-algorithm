#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, C;
vector<int> as, bs, cs;

ll solve() {
    vector<pair<int,int>> events;
    for (int i = 0; i < N; ++i) {
        events.push_back(make_pair(as[i], cs[i]));
        events.push_back(make_pair(bs[i]+1, -cs[i]));
    }
    sort(events.begin(), events.end());

    int time = 0;
    ll charge_per_day = 0;
    ll total_charge = 0;
    for (auto const& event : events) {
        int t, charge;
        tie(t, charge) = event;
        total_charge += (t - time) * min(ll(C), charge_per_day);
        charge_per_day += charge;
        time = t;
    }
    return total_charge;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> C;
    as.assign(N, 0);
    bs.assign(N, 0);
    cs.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> as[i] >> bs[i] >> cs[i];
    }
    cout << solve() << endl;

    return 0;
}