#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string solve(ll N) {
    if (N == 0) return "0";

    vector<char> A;
    for (int e = 1; e < 60 && N != 0; ++e) {
        if (N % (1L << e) == 0) {
            A.push_back('0');
        } else {
            A.push_back('1');
            if ((e-1) % 2 == 0) N -= (1L << (e-1));
            else N += (1L << (e-1));
        }
    }

    reverse(A.begin(), A.end());
    return string(A.begin(), A.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    cout << solve(N) << endl;

    return 0;
}