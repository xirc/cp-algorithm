#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

string solve(string const& S, int N) {
    auto rotate = [&](char c) -> char {
        int i = (c - 'A');
        i = (i + N) % 26;
        return ('A' + i);
    };
    vector<char> cs;
    transform(S.begin(), S.end(), back_inserter(cs), rotate);
    return string(cs.begin(), cs.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    string S;
    cin >> N >> S;
    cout << solve(S, N) << endl;

    return 0;
}