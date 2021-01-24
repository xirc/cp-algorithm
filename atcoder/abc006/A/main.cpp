#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    auto ans = N % 3 == 0 ? "YES" : "NO";
    cout << ans << endl;

    return 0;
}