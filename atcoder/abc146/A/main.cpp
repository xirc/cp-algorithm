#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<string> dow = {
        "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"
    };
    string S;

    cin >> S;
    int i = distance(dow.begin(), find(dow.begin(), dow.end(), S));
    int ans = (7 - i);
    cout << ans << endl;

    return 0;
}