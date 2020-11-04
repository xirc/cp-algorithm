#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> ABC(3, 0);
    cin >> ABC[0] >> ABC[1] >> ABC[2];
    sort(ABC.begin(), ABC.end());

    int ans = ABC[2] * 10 + ABC[1] + ABC[0];
    cout << ans << endl;

    return 0;
}