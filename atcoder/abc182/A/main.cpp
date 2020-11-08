#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int A, B;
    cin >> A >> B;
    int C = 2 * A + 100;
    int r = (C - B);
    cout << r << endl;

    return 0;
}