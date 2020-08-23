#include <bits/stdc++.h>

using namespace std;

int solve(const string& str) {
    int ans = 0;
    int i = 0;
    while (i + 1 < str.size()) {
        bool useOX = 
            (str[i] == 'O' && str[i+1] == 'X') ||
            (str[i] == 'X' && str[i+1] == 'O');
        if (useOX) {
            ans += 1;
            i += 2;
        } else {
            i++;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    string str;
    cin >> N >> str;
    cout << solve(str) << endl;

    return 0;
}