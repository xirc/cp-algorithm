#include <bits/stdc++.h>

using namespace std;

int solve(int N, vector<vector<int>>& ops) {
    priority_queue<int> even;
    priority_queue<int> odd;

    for (int i = 1; i <= N; ++i) {
        if (i & 1) odd.push(i);
        else even.push(i);
    }

    ops.clear();
    ops.reserve(N - 1);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        if (even.size() == 0) {
            a = odd.top(); odd.pop();
            b = odd.top(); odd.pop();
        } else if (odd.size() == 0) {
            a = even.top(); even.pop();
            b = even.top(); even.pop();
        } else {
            int odd_max = odd.top(), even_max = even.top();
            if (odd_max > even_max && odd.size() >= 2) {
                a = odd.top(); odd.pop();
                b = odd.top(); odd.pop();
            } else if (even_max > odd_max && even.size() >= 2) {
                a = even.top(); even.pop();
                b = even.top(); even.pop();
            } else {
                a = odd.top(), odd.pop();
                b = even.top(), even.pop();
            }
        }
        ops.push_back({ a, b });
        auto c = (a + b + 1) / 2;
        if (c & 1) odd.push(c);
        else even.push(c);
    }

    if (even.size()) return even.top();
    return odd.top();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N;
    vector<vector<int>> ops;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N;
        int ans = solve(N, ops);
        cout << ans << endl;
        for (auto op : ops) {
            cout << op[0] << " " << op[1] << endl;
        }
    }

    return 0;
}