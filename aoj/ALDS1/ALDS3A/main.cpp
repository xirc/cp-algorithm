#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    stack<int> S;
    string line, token;
    getline(cin, line);
    stringstream sin(line);
    while (!sin.eof()) {
        sin >> token;
        if (token == "+") {
            int rhs = S.top(); S.pop();
            int lhs = S.top(); S.pop();
            S.push(lhs + rhs);
        } else if (token == "-") {
            int rhs = S.top(); S.pop();
            int lhs = S.top(); S.pop();
            S.push(lhs - rhs);
        } else if (token == "*") {
            int rhs = S.top(); S.pop();
            int lhs = S.top(); S.pop();
            S.push(lhs * rhs);
        } else {
            int number = stoi(token);
            S.push(number);
        }
    }
    cout << S.top() << endl;

    return 0;
}