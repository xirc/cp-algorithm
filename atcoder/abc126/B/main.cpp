#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

bool isMM(string const& S, int i) {
    char a = S[i], b = S[i+1];
    if (a == '0') return b != '0';
    if (a == '1') return b == '0' || b == '1' || b =='2';
    return false;
}

string solve(string const& S) {
    auto a = isMM(S, 0);
    auto b = isMM(S, 2);
    if (a && b) return "AMBIGUOUS";
    if (a) return "MMYY";
    if (b) return "YYMM";
    return "NA";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    cout << solve(S) << endl;

    return 0;
}