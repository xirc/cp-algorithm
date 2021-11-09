#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<int> A;

bool solve() {
    vector<bool> used(N, false);
    for (auto v : A) {
        if (used[v-1]) return false;
        used[v-1] = true;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0);
    for (int &a : A) cin >> a;
    auto ans = solve() ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}