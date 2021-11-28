#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int Q;
    cin >> Q;

    priority_queue<int,vector<int>,greater<int>> A;
    deque<int> B;

    for (int i = 0; i < Q; ++i) {
        int c;
        cin >> c;
        if (c == 1) {
            int x;
            cin >> x;
            B.push_back(x);
        } else if (c == 2) {
            if (A.size() > 0) {
                cout << A.top() << endl;
                A.pop();
            } else {
                cout << B.front() << endl;
                B.pop_front();
            }
        } else if (c == 3) {
            for (auto x : B) A.push(x);
            B.clear();
        } else throw;
    }

    return 0;
}