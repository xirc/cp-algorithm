#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, A, B;
    cin >> N;
    if (N == 1) {
        cout << "Hello World" << endl;
    } else if (N == 2) {
        cin >> A >> B;
        cout << (A + B) << endl;
    } else throw;

    return 0;
}