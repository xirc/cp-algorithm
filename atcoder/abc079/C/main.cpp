#include <bits/stdc++.h>

using namespace std;

string solve(string ABCD) {
    for (int s = 0; s < 8; ++s) {
        bitset<3> bs(s);
        int v = ABCD[0] - '0';
        for (int i = 0; i < 3; ++i) {
            int d = ABCD[i+1] - '0';
            if (bs[i]) {
                v += d;
            } else {
                v -= d;
            }
        }
        if (v == 7) {
            vector<char> ans = { ABCD[0] };
            for (int i = 0; i < 3; ++i) {
                if (bs[i]) {
                    ans.push_back('+');
                } else {
                    ans.push_back('-');
                }
                ans.push_back(ABCD[i+1]);
            }
            ans.push_back('=');
            ans.push_back('7');
            return string(ans.begin(), ans.end());
        }
    }
    throw;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string ABCD;
    cin >> ABCD;
    cout << solve(ABCD) << endl;

    return 0;
}