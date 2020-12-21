#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    int L = 1900 * M + 100 * (N - M);
    int X = L * (1 << M);
    cout << X << endl;

    return 0;
}