#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

string cs = "abc";
void solve(int i, int N, vector<char>& s) {
    if (i == N) {
        cout << string(s.begin(), s.end()) << endl;
        return;
    }
    for (int j = 0; j < 3; ++j) {
        s.push_back(cs[j]);
        solve(i + 1, N, s);
        s.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<char> s;
    cin >> N;
    solve(0, N, s);

    return 0;
}