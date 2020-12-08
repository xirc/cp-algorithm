#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int p = min(A, B) + min(C, D);
    cout << p << endl;

    return 0;
}