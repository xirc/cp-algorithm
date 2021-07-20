#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    unordered_map<string,int> mp;

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string S;
        cin >> S;
        mp[S]++;
    }

    int maxc = 0;
    for (auto e : mp) {
        maxc = max(maxc, e.second);
    }
    vector<string> ws;
    for (auto e : mp) {
        if (maxc == e.second) {
            ws.push_back(e.first);
        }
    }
    sort(ws.begin(), ws.end());
    for (auto w : ws) {
        cout << w << endl;
    }

    return 0;
}