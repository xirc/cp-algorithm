#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    map<char, int> M;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        char ch;
        cin >> ch;
        ++M[ch];
    }
    if (M.size() == 3) {
        cout << "Three" << endl;
    } else {
        cout << "Four" << endl;
    }

    return 0;
}