#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int S;
    cin >> S;
    int h, m, s;
    s = S % 60;
    S /= 60;
    m = S % 60;
    S /= 60;
    h = S;

    cout << h << ":" << m << ":" << s << endl;

    return 0;
}