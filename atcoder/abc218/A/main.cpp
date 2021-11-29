#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    string S;

    cin >> N >> S;
    auto ans = (S[N-1] == 'o' ? "Yes" : "No");
    cout << ans << endl;

    return 0;
}