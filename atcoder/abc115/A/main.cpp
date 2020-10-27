#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T = 25;
    int D;
    cin >> D;
    cout << "Christmas";
    T -= D;
    while (T > 0) {
        cout << " Eve";
        --T;
    }
    cout << endl;

    return 0;
}