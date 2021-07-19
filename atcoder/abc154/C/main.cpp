#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    unordered_set<int> S;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        S.insert(a);
    }
    string ans = (S.size() == N) ? "YES" : "NO";
    cout << ans << endl;

    return 0;
}