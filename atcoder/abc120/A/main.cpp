#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int A, B, C;
    cin >> A >> B >> C;
    int ans = min(C, B / A);
    cout << ans << endl;

    return 0;
}