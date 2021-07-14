#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<bool> ac(N, false);
    vector<int> wa(N, 0);
    for (int i = 0; i < M; ++i) {
        int p;
        string S;

        cin >> p >> S;
        --p;
        if (S == "AC") {
            ac[p] = true;
        } else if (S == "WA") {
            if (!ac[p]) wa[p]++;
        } else throw;
    }

    int numAC = 0, numWA = 0;
    for (int i = 0; i < N; ++i) {
        if (ac[i]) ++numAC;
        if (ac[i]) numWA += wa[i];
    }

    cout << numAC << " " << numWA << endl;

    return 0;
}