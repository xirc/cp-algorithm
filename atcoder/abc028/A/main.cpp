#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    if (N < 60) {
        cout << "Bad" << endl;
    } else if (N < 90) {
        cout << "Good" << endl;
    } else if (N < 100) {
        cout << "Great" << endl;
    } else {
        cout << "Perfect" << endl;
    }

    return 0;
}