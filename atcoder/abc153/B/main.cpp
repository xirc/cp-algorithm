#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, H;
    vector<int> A;
    
    cin >> H >> N;
    A.assign(N, 0);
    for (auto &a : A) cin >> a;
    int W = accumulate(A.begin(), A.end(), 0, plus<int>());
    auto ans = (W >= H ? "Yes" : "No");
    cout << ans << endl;

    return 0;
}