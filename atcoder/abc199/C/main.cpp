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
    string L = S.substr(0, N);
    string R = S.substr(N, N);

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int T, A, B;
        cin >> T >> A >> B;
        --A, --B;
        if (T == 1) {
            if (A >= N) {
                swap(R[A-N], R[B-N]);
            } else if (B >= N) {
                swap(L[A], R[B-N]);
            } else {
                swap(L[A], L[B]);
            }
        } else if (T == 2) {
            swap(L, R);
        }
    }
    cout << L << R << endl;

    return 0;
}