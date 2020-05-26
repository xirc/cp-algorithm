#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b;
    cin >> a >> b;
    int area = a * b, perimeter = 2*(a+b);
    cout << area << " " << perimeter << endl;

    return 0;
}