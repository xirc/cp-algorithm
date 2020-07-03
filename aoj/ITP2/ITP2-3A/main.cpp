#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int mini = min({ a, b, c });
    int maxi = max({ a, b, c });
    cout << mini << " " << maxi << endl;

    return 0;
}