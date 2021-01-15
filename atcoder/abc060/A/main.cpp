#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string A, B, C;
    cin >> A >> B >> C;
    if (A[A.size()-1] == B[0] && B[B.size()-1] == C[0]) {
        cout<< "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}