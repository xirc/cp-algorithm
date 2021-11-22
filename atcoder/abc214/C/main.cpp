#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> S, T;

    cin >> N;
    S.assign(N, 0);
    for (int i = 0; i < N; ++i) cin >> S[i];
    T.assign(N, 0);
    for (int i = 0; i < N; ++i) cin >> T[i];

    queue<int> Q;
    for (int i = 0; i < N; ++i) {
        Q.push(i);
    }
    while (Q.size() > 0) {
        auto i = Q.front(); Q.pop();
        int j = (i+1)%N;
        if (T[i] + S[i] < T[j]) {
            T[j] = T[i] + S[i];
            Q.push(j);
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << T[i] << endl;
    }

    return 0;
}