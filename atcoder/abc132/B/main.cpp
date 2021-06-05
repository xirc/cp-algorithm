#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> ps;
    cin >> N;
    ps.assign(N, 0);
    for (auto &p : ps) cin >> p;
    int count = 0;
    for (int i = 1; i + 1 < N; ++i) {
        if (ps[i] > ps[i-1] && ps[i] < ps[i+1]) ++count;
        if (ps[i] < ps[i-1] && ps[i] > ps[i+1]) ++count;
    }
    cout << count << endl;

    return 0;
}