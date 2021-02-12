#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    int N, l, r;
    
    cin >> S;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> l >> r;
        --l, --r;
        reverse(S.begin() + l, S.begin() + r + 1);
    }
    cout << S << endl;

    return 0;
}