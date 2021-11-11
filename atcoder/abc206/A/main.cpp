#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    int price_with_tax = int(N * ff(1.08));
    int const fixed_price = 206;
    if (price_with_tax < fixed_price) {
        cout << "Yay!" << endl;
    } else if (price_with_tax > fixed_price) {
        cout << ":(" << endl;
    } else {
        cout << "so-so" << endl;
    }

    return 0;
}