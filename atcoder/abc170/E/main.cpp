#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int const inf = numeric_limits<int>::max();
    int const M = 2e5;

    int N; int Q;
    cin >> N >> Q;

    vector<int> rate(N);
    vector<int> school(N);
    multiset<int> max_rates;
    vector<multiset<int>> rates(M);
    for (int i = 0; i < N; ++i) {
        int A, B;
        cin >> A >> B;
        --B;
        rate[i] = A;
        school[i] = B;
        rates[B].insert(A);
    }
    for (auto const& rs : rates) {
        int max_rate = rs.empty() ? inf : *rs.rbegin();
        max_rates.insert(max_rate);
    }

    for (int tt = 0; tt < Q; ++tt) {
        int C, D;
        cin >> C >> D;
        --C, --D;
        int B = school[C];
        school[C] = D;

        int pb = *rates[B].rbegin();
        int pd = rates[D].empty() ? inf : *rates[D].rbegin();

        rates[B].erase(rates[B].find(rate[C]));
        rates[D].insert(rate[C]);

        int nb = rates[B].empty() ? inf : *rates[B].rbegin();
        int nd = *rates[D].rbegin();

        max_rates.erase(max_rates.find(pb));
        max_rates.erase(max_rates.find(pd));
        max_rates.insert(nb);
        max_rates.insert(nd);

        int fairness = *max_rates.begin();
        cout << fairness << endl;
    }

    return 0;
}