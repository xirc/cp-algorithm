#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<stack<int>> stacks(N);
    for (int i = 0; i < Q; ++i) {
        int type, t;
        cin >> type >> t;
        if (type == 0) {
            int x;
            cin >> x;
            stacks[t].push(x);
        } else if (type == 1) {
            if (stacks[t].size()) {
                auto x = stacks[t].top();
                cout << x << endl;
            }
        } else if (type == 2) {
            if (stacks[t].size()) {
                stacks[t].pop();
            }
        } else throw;
    }

    return 0;
}