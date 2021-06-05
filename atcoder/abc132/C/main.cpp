#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> ds;

    cin >> N;
    ds.assign(N, 0);
    for (auto &d : ds) cin >> d;

    sort(ds.begin(), ds.end());
    int l = (N-1) / 2;
    int r = N / 2;
    cout << (ds[r] - ds[l]) << endl;

    return 0;
}