#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int A, B;
    cin >> A >> B;
    int C = A + B;
    if (C >= 10) {
        cout << "error" << endl;
    } else {
        cout << C << endl;
    }

    return 0;
}