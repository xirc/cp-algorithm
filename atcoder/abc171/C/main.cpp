#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string solve(ll N) {
    vector<char> cs;
    while (N > 0) {
        --N;
        int p = N % 26;
        cs.push_back('a' + p);
        N /= 26;
    }
    reverse(cs.begin(), cs.end());
    return string(cs.begin(), cs.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll N;
    cin >> N;
    cout << solve(N) << endl;

    return 0;
}