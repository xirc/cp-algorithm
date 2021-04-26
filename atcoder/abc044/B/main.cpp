#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string w;
    cin >> w;

    unordered_map<char,int> charCounter;
    for (auto c : w) {
        charCounter[c]++;
    }
    auto beautiful = true;
    for (auto kv : charCounter) {
        if (kv.second % 2 == 1) {
            beautiful = false;
            break;
        }
    }
    cout << (beautiful ? "Yes" : "No") << endl;

    return 0;
}