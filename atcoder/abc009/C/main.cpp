#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int diff(string const& S, string const& R) {
    assert(S.size() == R.size());
    int count = 0;
    for (int i = 0; i < (int)S.size(); ++i) {
        count += S[i] != R[i] ? 1 : 0;
    }
    return count;
}

string solve(int const N, int const K, string const& S) {
    string L = S;
    for (int i = 0; i < N; ++i) {
        int j = i;
        for (int k = i + 1; k < N; ++k) {
            if (L[k] >= L[j]) continue;
            string R = L;
            swap(R[i], R[k]);
            if (diff(S, R) <= K) {
                j = k;
            }
        }
        swap(L[i], L[j]);
    }
    return L;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    string S;
    cin >> N >> K >> S;
    cout << solve(N, K, S) << endl;

    return 0;
}