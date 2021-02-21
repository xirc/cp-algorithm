#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using lf = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, A;

    unordered_map<int,int> mp;
    int ans = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A;
        if (mp.count(A) > 0) {
            ++ans;
        }
        ++mp[A];
    }
    cout << ans << endl;

    return 0;
}