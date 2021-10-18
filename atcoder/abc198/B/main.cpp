#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    while (N > 0 && N % 10 == 0) {
        N /= 10;
    }

    vector<int> ds;
    while (N > 0) {
        ds.push_back(N % 10);
        N /= 10;
    }

    bool is_palindrome = true;
    for (int i = 0; i < ds.size(); ++i) {
        int j = ds.size() - 1 - i;
        if (j <= i) break;
        if (ds[i] != ds[j]) {
            is_palindrome = false;
            break;
        }
    }
    cout << (is_palindrome ? "Yes" : "No") << endl;

    return 0;
}