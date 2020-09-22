#include <bits/stdc++.h>

using namespace std;

int solve(string const& S, int N) {
    int Ro = 0, Re = 0, Bo = 0, Be = 0;
    for (int i = 0; i < N; ++i) {
        const int d = (S[i] - '0');
        const int o = (d % 2 == 0) ? 0 : 1;
        const int e = (d % 2 == 0) ? 1 : 0;
        if ((i + 1) % 2 == 0) {
            // Breach
            Bo += o;
            Be += e;
        } else {
            // Raze
            Ro += o;
            Re += e;
        }
    }
    while (Ro + Re + Bo + Be > 2) {
        if (Re > 0) --Re;
        else --Ro;
        if (Bo > 0) --Bo;
        else --Be;
    }
    if (Ro + Re + Bo + Be == 1) {
        if (Ro > 0 || Bo > 0) return 1;
        else return 2;
    } else {
        if (Bo > 0) return 1;
        else return 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T, N;
    string S;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N >> S;
        cout << solve(S, N) << endl;
    }

    return 0;
}