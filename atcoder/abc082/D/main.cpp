#include <bits/stdc++.h>

using namespace std;

string S;
int X, Y;

bool solve() {
    const int N = S.size(); 

    vector<int> xs;
    vector<int> ys;

    int i;
    for (i = 0; i < N; ++i) {
        if (S[i] == 'T') break;
    }
    int ix = i;

    bool dx = true;
    int v = 0;
    for (; i < N; ++i) {
        auto c = S[i];
        if (c == 'F') {
            ++v;
        } else if (c == 'T') {
            if (dx) {
                if (v > 0) xs.push_back(v);
            } else {
                if (v > 0) ys.push_back(v);
            }
            dx ^= true;
            v = 0;
        } else throw;
    }
    if (v > 0) {
        if (dx) xs.push_back(v);
        else ys.push_back(v);
    }

    set<int> cxs, nxs;
    cxs.insert(ix);
    for (int x : xs) {
        nxs.clear();
        for (auto cx : cxs) {
            nxs.insert(cx + x);
            nxs.insert(cx - x);
        }
        swap(cxs, nxs);
    }

    set<int> cys, nys;
    cys.insert(0);
    for (int y : ys) {
        nys.clear();
        for (auto cy : cys) {
            nys.insert(cy + y);
            nys.insert(cy - y);
        }
        swap(cys, nys);
    }

    return (cxs.count(X) > 0 && cys.count(Y) > 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> S;
    cin >> X >> Y;
    auto ans = solve() ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}