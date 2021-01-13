#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    string S;
    cin >> N >> S;
    
    int maxx = 0;
    int x = 0;
    for (auto ch : S) {
        if (ch == 'I') ++x;
        if (ch == 'D') --x;
        maxx = max(maxx, x);
    }
    cout << maxx << endl;

    return 0;
}