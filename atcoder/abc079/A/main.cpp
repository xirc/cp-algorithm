#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string N;
    cin >> N;
    if (N[0] == N[1] && N[1] == N[2]) {
        cout << "Yes" << endl;
    } else if (N[1] == N[2] && N[2] == N[3]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}