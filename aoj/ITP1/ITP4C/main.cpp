#include <bits/stdc++.h>

using namespace std;

int solve(string op, int a, int b) {
    switch (op[0])
    {
    case '+':
        return a+b;
    case '-':
        return a-b;
    case '*':
        return a*b;
    case '/':
        return a/b;
    default:
        throw;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (true) {
        int a, b;
        string op;

        cin >> a >> op >> b;
        if (op == "?") break;
        cout << solve(op, a, b) << endl;
    }

    return 0;
}