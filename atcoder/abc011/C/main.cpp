#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int N;
vector<int> G(3);

bool solve() {
    if (find(G.begin(), G.end(), N) != G.end()) return false;
    int c = 0;
    while (N > 0) {
        int PN = N;
        for (int x = 3; x > 0; --x) {
            if (N - x < 0) continue;
            bool pass = true;
            for (int i = 0; i < 3; ++i) {
                if (G[i] == N - x) {
                    pass = false;
                }
            }
            if (pass) {
                N = N - x;
                ++c;
                break;
            }
        }
        if (PN == N) return false;
    }
    return c <= 100;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    cin >> G[0] >> G[1] >> G[2];
    auto ans = solve() ? "YES" : "NO";
    cout << ans << endl;

    return 0;
}