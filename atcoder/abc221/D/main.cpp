#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<array<int,2>> events;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        events.push_back({ a, 1 });
        events.push_back({ a + b , 0 });
    }
    sort(events.begin(), events.end());

    int t = 0;
    int users = 0;
    vector<int> ans(N+1, 0);
    for (auto const& event : events) {
        int dt = event[0] - t;
        if (event[1] == 1) {
            // log in
            ans[users] += dt;
            users += 1;
        } else {
            // log out
            ans[users] += dt;
            users -= 1;
        }
        t = event[0];
    }
    
    for (int i = 1; i <= N; ++i) {
        if (i > 1) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}