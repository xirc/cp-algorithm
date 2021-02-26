#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

vector<string> scales = { "Do", "Do#", "Re", "Re#", "Mi", "Fa", "Fa#", "So", "So#", "La", "La#", "Si" };
string scale = "WBWBWWBWBWBW";
string scale3 = scale + scale + scale;

string solve(string const& S) {
    for (int i = 0; i < scales.size(); ++i) {
        bool match = true;
        for (int j = 0; j < S.size(); ++j) {
            if (scale3[i+j] != S[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            return scales[i];
        }
    }
    return "??";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    cout << solve(S) << endl;

    return 0;
}