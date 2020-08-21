#include <bits/stdc++.h>

using namespace std;

const int max_message_count = 75;
const vector<vector<char>> M = {
    { '.', ',', '!', '?', ' ' },
    { 'a', 'b', 'c' },
    { 'd', 'e', 'f' },
    { 'g', 'h', 'i' },
    { 'j', 'k', 'l' },
    { 'm', 'n', 'o' },
    { 'p', 'q', 'r', 's' },
    { 't', 'u', 'v' },
    { 'w', 'x', 'y', 'z' },
};
string solve(const string& str) {
    vector<char> ans;
    ans.reserve(max_message_count);
    
    int cur_dig = 0;
    int count = 0;
    for (auto ch : str) {
        int dig = ch - '0';
        if (dig == 0) {
            if (count > 0) {
                int sz = M[cur_dig-1].size();
                ans.push_back(M[cur_dig-1][(count - 1) % sz]);
                cur_dig = count = 0;
            }
        } else if (cur_dig == 0) {
            cur_dig = dig;
            count = 1;
        } else if (cur_dig == dig) {
            ++count;
        } else throw;
    }

    return string(ans.begin(), ans.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    string s;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> s;
        cout << solve(s) << endl;
    }

    return 0;
}