#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    string S;

    cin >> N >> K >> S;
    S[K-1] = tolower(S[K-1]);
    cout << S << endl;

    return 0;
}