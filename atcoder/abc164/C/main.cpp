#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    set<string> prizes;

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        prizes.insert(s);
    }
    cout << prizes.size() << endl;

    return 0;
}