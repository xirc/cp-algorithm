#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    string S;
    cin >> N >> S;
    deque<char> cs;
    for (auto c : S) {
        if (cs.empty() || cs.back() != c) {
            cs.push_back(c);
        }
    }
    cout << cs.size() << endl;

    return 0;
}