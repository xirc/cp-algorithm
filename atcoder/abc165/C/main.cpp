#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, M;
int Q;
vector<array<int,4>> QS;

int solve(vector<int>& seq) {
    if ((int)seq.size() == N) {
        int ans = 0;
        for (auto const& abcd : QS) {
            int a = abcd[0], b = abcd[1], c = abcd[2], d = abcd[3];
            if (seq[b] - seq[a] == c) {
                ans += d;
            }
        }
        return ans;
    }

    int ans = 0;
    int lb = seq.back();
    for (int v = lb; v <= M; ++v) {
        seq.push_back(v);
        ans = max(ans, solve(seq));
        seq.pop_back();
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> Q;
    for (int i = 0; i < Q; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        --a, --b;
        QS.push_back({ a, b, c, d });
    }

    vector<int> buf = { 1 };
    cout << solve(buf) << endl;

    return 0;
}