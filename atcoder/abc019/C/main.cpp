#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int N;
vector<int> A;

int solve() {
    unordered_set<int> S;
    for (int i = 0; i < N; ++i) {
        int v = A[i];
        while (v % 2 == 0) v /= 2;
        S.insert(v);
    }
    return S.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout << solve() << endl;

    return 0;
}