#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    int x = N * 800;
    int y = N / 15 * 200;
    cout << x - y << endl;

    return 0;
}