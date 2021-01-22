#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int T, N, M;
vector<int> A, B;

bool solve() {
    vector<vector<int>> ss;
    for (int a : A) {
        ss.push_back({ a, -1 });
    }
    for (int b : B) {
        ss.push_back({ b, 1 });
    }
    sort(ss.begin(), ss.end());

    deque<int> Q;
    for (auto e : ss) {
        auto t = e[0], q = e[1];
        while (!Q.empty() && Q.front() + T < t)
        {
            Q.pop_front();
        }
        if (q < 0) {
            Q.push_back(t);
        } else if (Q.size() > 0) {
            Q.pop_front();
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cin >> M;
    B.assign(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }
    auto ans = solve() ? "yes" : "no";
    cout << ans << endl;

    return 0;
}