#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string N;
    cin >> N;
    for (int i =0; i < 3; ++i) {
        if (N[i] == '1') {
            N[i] = '9';
        } else if (N[i] == '9') {
            N[i] = '1';
        } else throw;
    }
    cout << N << endl;

    return 0;
}