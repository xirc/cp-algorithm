#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string A, B;
    cin >> A >> B;
    int NA = A.size(), NB = B.size();
    
    if (NA > NB || (NA == NB && A > B)) {
        cout << "GREATER" << endl;
    } else if (NA < NB || (NA == NB && A < B)) {
        cout << "LESS" << endl;
    } else {
        cout << "EQUAL" << endl;
    }

    return 0;
}