#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    int price = 700;
    for (int i = 0; i < 3; ++i) {
        if (S[i] == 'o') price += 100;
    }
    cout << price << endl;

    return 0;
}