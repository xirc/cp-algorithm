#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    vector<priority_queue<int>> queues(N);
    for (int i = 0; i < Q; ++i) {
        int type, t;
        cin >> type >> t;
        auto& queue = queues[t];
        if (type == 0) {
            int x;
            cin >> x;
            queue.push(x);
        } else if (type == 1) {
            if (queue.size()) {
                cout << queue.top() << endl;
            }
        } else if (type == 2) {
            if (queue.size()) {
                queue.pop();
            }
        } else throw;
    }

    return 0;
}