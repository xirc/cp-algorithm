#include <bits/stdc++.h>

using namespace std;

int A, B, C, D, E, F;
vector<int> solve() {
    set<int> ws, ss;
    for (int i = 0; i <= 3000; ++i) {
        int wa = A * i * 100;
        int sc = C * i;
        for (int j = 0; j <= 3000; ++j) {
            int wb = B * j * 100;
            int sd = D * j;
            if (wa + wb <= F) {
                ws.insert(wa + wb);
            }
            if (sc + sd <= F) {
                ss.insert(sc + sd);
            }
        }
    }

    double maxd = 0;
    int maxw = 100 * A, maxs = 0;
    for (auto w : ws) {
        for (auto s : ss) {
            if (w + s > F) continue;
            if (s > w / 100 * E) continue;
            double d = s * 100.0 / (w + s);
            if (d > maxd) {
                maxd = d;
                maxw = w, maxs = s;
            }
        }
    }
    return { maxw + maxs, maxs };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> A >> B >> C >> D >> E >> F;
    auto ans = solve();
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}