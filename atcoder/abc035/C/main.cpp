#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    vector<int> A(N+1, 0);
    for (int i = 0; i < Q; ++i) {
        int l, r;
        cin >> l >> r;
        --l, --r; // 0index
        A[l] += 1;
        A[r+1] -= 1;
    }
    for (int i = 1; i < N; ++i) {
        A[i] += A[i-1];
    }
    vector<char> s(N, ' ');
    for (int i = 0; i < N; ++i) {
        if (A[i] & 1) s[i] = '1';
        else s[i] = '0';
    }
    cout << string(s.begin(), s.end()) << endl;

    return 0;
}