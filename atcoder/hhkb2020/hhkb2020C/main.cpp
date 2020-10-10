#include <bits/stdc++.h>

using namespace std;

void solve(int N, vector<int> const& P) {
    vector<bool> F(200000+10, false);
    int mini = 0;
    for (auto v : P) {
        F[v] = true;
        if (v == mini) {
            while (F[mini]) ++mini;
        }
        cout << mini << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> P;

    cin >> N;
    P.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }
    solve(N, P);

    return 0;
}