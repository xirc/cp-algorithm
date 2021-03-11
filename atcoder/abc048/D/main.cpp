#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

bool solve(string const& s) {
    const int N = s.size();
    auto a = s[0], b = s[s.size()-1];
    int m = 0;
    if (a == b) {
        int len = 0;
        for (int i = 1; i < N; ++i) {
            if (s[i] != a){
                ++len;
                continue;
            }
            m += len - 1;
            len = 0;
        }
    } else { // a != b
        bool useB = true;
        for (int i = 1; i < N; ++i) {
            auto c = useB ? b : a;
            if (s[i] != c) {
                ++m;
            } else {
                useB ^= true;
            }
        }
    }
    return m % 2 == 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    auto ans = solve(s) ? "First" : "Second";
    cout << ans << endl;

    return 0;
}