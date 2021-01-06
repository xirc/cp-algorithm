#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
string S;

string solve() {
    deque<char> Q;
    int k = 0;
    for (auto c : S) {
        if (c == '(') {
            Q.push_back(c);
            k++;
        } else if (c == ')') {
            Q.push_back(c);
            if (k > 0) --k;
            else Q.push_front('(');
        }
    }
    while (k > 0) {
        Q.push_back(')');
        --k;
    }
    return string(Q.begin(), Q.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> S;
    cout << solve() << endl;

    return 0;
}