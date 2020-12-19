#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, A, B;
    cin >> N >> A >> B;
    int c = min(A * N, B);
    cout << c << endl;

    return 0;
}