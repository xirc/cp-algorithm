#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    map<string,int> mp;

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
    for (auto e : mp) {
        if (maxc == e.second) {
            cout << e.first << endl;
        }
    }

    return 0;
}