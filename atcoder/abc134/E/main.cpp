#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<int> A;

int solve() {
    multiset<int> ls;
    for (auto x : A) {
        auto it = ls.upper_bound(x-1);
        if (it != ls.begin()) {
            --it;
            ls.erase(it);
        }
        ls.insert(x);
    }
    return ls.size();
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