#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B;
    cin >> A >> B;
    bool ans = (A * B) & 1;
    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}