#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int N, a;
string k;
vector<int> bs;

array<int,2> find_loop() {
    vector<int> ds(N, -1);
    ds[a] = 0;
    int v = a;
    while (true) {
        int u = bs[v];
        if (ds[u] < 0) {
            ds[u] = ds[v] + 1;
            v = u;
        } else {
            int T = ds[u];
            int C = ds[v] - ds[u] + 1;
            return { T, C };
        }
    }
}

int solve() {
    auto TC = find_loop();
    int T = TC[0], C = TC[1];

    int m = 0;
    if (k.size() >= 7) {
        for (int i = 0; i < (int)k.size(); ++i) {
            m = (m * 10 + (k[i] - '0')) % C;
        }
        while (m < T) {
            m += C;
        }
    } else {
        m = stoi(k);
        if (m >= T) {
            m %= C;
            while (m < T) {
                m += C;
            }
        }
    }

    int v = a;
    while (m > 0) {
        v = bs[v];
        --m;
    }
    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> a >> k;
    --a;
    bs.assign(N, 0);
    for (auto &bi : bs) {
        cin >> bi;
        --bi;
    }
    cout << (solve() + 1) << endl;

    return 0;
}