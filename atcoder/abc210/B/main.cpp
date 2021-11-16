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
    
    int i;
    for (i = 0; i < N; ++i) {
        if (S[i] == '1') break;
    }
    auto ans = (i % 2 == 0) ? "Takahashi" : "Aoki";
    cout << ans << endl;

    return 0;
}