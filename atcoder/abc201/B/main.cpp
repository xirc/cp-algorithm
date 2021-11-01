#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<pair<int,string>> mountains;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        string S; int T;
        cin >> S >> T;
        mountains.push_back({ T, S });
    }
    sort(mountains.begin(), mountains.end());
    reverse(mountains.begin(), mountains.end());
    cout << mountains[1].second << endl;

    return 0;
}