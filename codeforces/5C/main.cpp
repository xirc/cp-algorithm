// http://codeforces.com/contest/5/problem/C

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

// )((())))(()())
// 01111110111111
pair<int,int> solve(const string& str) {
    const int N = str.size();
    vector<bool> v(N, false);
    stack<int> S;
    for (int i = 0; i < N; ++i) {
        if (str[i] == '(') {
            S.push(i);
        } else { // ')'
            if (!S.empty()) {
                int j = S.top(); S.pop();
                v[i] = v[j] = true;
            }
        }
    }

    int longest = 0;
    int count = 1;
    int length = 0;
    for (int i = 0; i < N; ++i) {
        if (v[i]) {
            length++;
            if (longest == length) {
                count++;
            } else if (length > longest) {
                longest = length;
                count = 1;
            }
        } else {
            length = 0;
        }
    }
    return { longest, count };
}

int main() {
    string s;
    cin >> s;
    auto ans = solve(s);
    cout << ans.first << " " << ans.second << endl;
}